###########################################################################
#
#    #include<iostream>
#    using namespace std;
#    int sum(int n) {
#        if (n == 1) {
#            return 1;
#        }
#        return n+sum(n-1);
#    }
#
#    int main() {
#      int n = 10;
#      int result = sum(n);
#      cout << result << endl;
#      return 0;
#    }
#
###########################################################################

.text
.globl main
main:
    addi    $s0, $0, 1 # 限定条件 n == 1
    addi    $s1, $0, 10 # 累加上限
    addi    $a0, $0, 0 # 储存结果

    jal     sum
    j       exit

sum:
    addi    $sp, $sp, -8 # 4 * 2 个变量储存
    sw      $ra, 0($sp)
    sw      $s1, 4($sp)

    beq     $s0, $s1, cal # 终结递归

    addi    $s1, $s1, -1

    jal     sum # 未终结之前继续压栈

cal:
    lw      $v1, 4($sp) # 必须 lw 出来才行？
    lw      $ra, 0($sp)
    add     $a0, $a0, $v1
    addi    $sp, $sp, 8

    jr       $ra

exit:
    # move    $a0, $v0
    li      $v0, 1
    syscall

    li      $v0, 10
    syscall



