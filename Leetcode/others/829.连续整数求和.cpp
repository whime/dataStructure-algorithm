//给定一个正整数 N，试求有多少组连续正整数满足所有数字之和为 N
/**
有点难理解。
依次判断当有i个连续数字时，是否满足条件；
当有i+1个数字时，数组中第i+1个数与第一个数的差为i，
每个循环temp加上这个差值，若与i取余的值和N与i取余的值相等，那么这些连续整数的开始的元素就是N/i。
*/
class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int res=1;
        int temp=0;
        for(int i=2;i<N;i++)
        {
            temp+=i-1;//长度为i的数组的最后一个数和第一个数的差值
            if(temp>=N)
            {
                break;
            }
            if(temp%i==N%i) res++;
        }
        return res;
    }
};