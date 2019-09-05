# int i = 10;
# for(int i = 0; i < 10 ; i++) {
#    for(int j = 0; j < i; j++) {
#         a = wrod[f];
#         b = word[f + 1];
#         c = (a < b)
#         if(c == 0) swap(a, b);
#     }
# }
# print array

.text
.globl main
    
main:    
    add     $s0, $0, 10     # i = 10
loop1:
    beqz    $s0, print      # i == 0
    sub     $s0, $s0, 1     # i--
    add     $s1, $0, 0      # j = 0
    la      $a2, data       # gain address of data
loop2:
    beq     $s0, $s1, loop1 #  j == i
    add     $s1, $s1, 1     # j++
    lw      $t0, 0($a2)     # a = word[f]
    lw      $t1, 4($a2)     # b = word[f+1]
    slt     $t3, $t1, $t0   # c = (a < b)
    beqz    $t3, swap       # if c == 0
    add     $a2, $a2, 4     # f++
    j       loop2
swap:                       # swap(a, b)
    sw      $t1, 0($a2)
    sw      $t0, 4($a2)
    add     $a2, $a2, 4     # f++
    j       loop2
print:                      # print(array[i] + '\n')
    la      $a2, data       # gain address of word
    la		$a1, change     # gain address of change
    add     $s3, $0, 10
loop3:                      # loop for print
    beqz    $s3, exit
    sub     $s3, $s3, 1
    lw      $t0, 0($a2)
    move 	$a0, $t0
    add     $a2, $a2, 4
    li		$v0, 1
    syscall
    move    $a0, $a1
    li      $v0, 4
    syscall
    j       loop3
exit:
    li      $v0, 10
    syscall

.data
    change:
        .asciiz "\n"
    changed:
        .asciiz " "
    data:
        .word 21,4,12,6,89,17,33,10,9,51