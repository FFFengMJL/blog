.text
.globl main
main:
    move    $t0, $0
    move    $t1, $0
    la      $a1, change
    la      $a2, data

loop:
    lw 	    $t0, 0($a2)
    add     $a2, $a2, 4
    add     $t1, $t1, $t0
    move 	$a0, $t0		# $a0 = $01
    beqz    $t0, exit
    li      $v0, 1
    syscall
    la      $a0, change
    li      $v0, 4
    syscall

    j       loop
exit:
    move    $a0, $t1
    li      $v0, 1
    syscall
    li      $v0, 10
    syscall

.data
    change:
        .asciiz "\n"
    data:
        .word 21,4,12,6,89,17,33,10,9,51