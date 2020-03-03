.text
.globl main

main:
loop:
    add $s2, $s1, $s2
    beq $s1, 10, exit
    add $s1, $s1, 1
    j loop
exit:
    move $a1, $s2
    li $v0, 1
    syscall
    li $v0, 10
    syscall
