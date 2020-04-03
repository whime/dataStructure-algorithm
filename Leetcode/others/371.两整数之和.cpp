//不使用运算符 + 和 - ，计算两整数a 、b 之和。
class Solution {
public:
    int getSum(int a, int b) {
        //&操作计算每一位的进位，异或表示不考虑进位的简单相加。
        //递归直到进位为零
        return b==0?a:getSum(a^b,unsigned(a&b)<<1);
    }
};