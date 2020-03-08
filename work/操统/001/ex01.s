#ex01.s

.section .data
    array:
        .int 12,4,5,7,80,34,54,46,3,23
    output:
        .ascii "The minimum number is %d and the average number is %d\n"
        len = . - output
.globl _start
_start:
    movl $0, %ecx # 次数
    movl array(, %ecx, 4), %eax # 求均值
    movl array(, %ecx, 4), %ebx # 求最小值
    LPCMP: # 比较和累加
        addl $1, %ecx
        movl array(, %ecx, 4), %edx # 加载数
        add %edx, %eax
        cmp %ebx, %edx
        cmovl %edx, %ebx # if <, ebx = edx
        cmp $9, %ecx
        jne LPCMP
        je END
    END:
        movl $0, %edx
        movl $10, %ecx
        divl %ecx # 得到除法结果
        pushl %ebx
        pushl %eax
        pushl $output
        call printf
        pushl $0
        call exit # 程序终止
