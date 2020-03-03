# input -> sort -> output
.text
.globl main

# 输入
# int n = 10;
# int* p = start;
# int temp = 0;
# while(n--) {
#     cin >> temp;
#     *p = temp;
#     p++;
# }
main:
    addi    $s0, $0, 10     # constant n

    add     $v1, $0, $s0    # int n = 10;
    la      $a1, nums       # int* p = start;
input:
    beqz    $v1, sort       # if n == 0, input is over, go to sort
    addi    $v1, $v1, -1    # n--;

    li      $v0, 5          # cin >> temp;
    syscall
    
    sw      $v0, 0($a1)     # *p = temp;
    addi    $a1, $a1, 4     # p++;
    j       input           # loop



# bubble sort

# mainLoop
# int* p = start;
# int i = n;
# while (i--) {
#     for (int j = 0; j < i; j++) {
#         if (p[j + 1] < p[j]) {
#             swap(p[j + 1], p[j]);
#         }
#     }
# }
sort:
    addi    $t0, $s0, 0     # int i = 10;
mainLoop:
    beqz    $t0, before_output
    la      $a1, nums
    addi    $t0, $t0, -1    # i--;
    addi    $t1, $0, 0      # int j = 0;

    jal     inLoop          # in the second loop

inLoop:
    beq     $t1, $t0, mainLoop
    lw      $t2, 0($a1)     # a = p[j]
    lw      $t3, 4($a1)     # b = p[j + 1]
    slt     $t4, $t3, $t2   # if a < b
    beqz    $t4, swap       # swap(a,b)
    jal     addp

# method
# swap(int &a, int &b) {
#     int temp = a;
#     a = b;
#     b = temp;
# }
swap:
    sw      $t3, 0($a1)
    sw      $t2, 4($a1)
    jal     addp

# jump to appd is aim to make p++

addp:
    addi    $a1, $a1, 4
    addi    $t1, $t1, 1    # j++;
    j       inLoop          # back to inLoop

# output
# int n = 10;
# int* p = start;
# while (n--) {
#     cout << *p;
#     cout << ' ';
#     p--;
# }
before_output:
    add     $v1, $0, $s0    # int n = 10;
    la      $a2, space      # ' '
    la      $a1, nums
output:
    beqz    $v1, exit       # if n == 0, output is over, go to exit
    addi    $v1, $v1, -1    # n--;

    lw      $a0, 0($a1)     # cout << p[n];
    li      $v0, 1
    syscall

    move    $a0, $a2        # cout << endl;
    li      $v0, 4
    syscall

    addi    $a1, $a1, 4     # p++;

    jal     output          # loop



exit:
    li      $v0, 10
    syscall

.data
    space:
        .asciiz " "
    nums:
        .word 0,0,0,0,0,0,0,0,0,0