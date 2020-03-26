/**
一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
*/
//dp[i]=dp[i-1]+dp[i-2],i>1
class Solution {
public:
    int numWays(int n) {
        if(n==0) return 1;
        if(n<3) return n;
        int a=1,b=2,tmp;
        for(int i=3;i<=n;i++)
        {
            tmp=(a+b)%1000000007;
            a=b;
            b=tmp;
        }
        return b;
    }
};