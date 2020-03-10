//给定一个字符串s，找到其中最长的回文子序列。可以假设s的最大长度为1000。
//时间和空间复杂度都为O(N^2)
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int left=0,right=0,i=0;
        int size=s.length();
        int **dp=new int*[size];//打表，只需存储上三角区域
        for(int i=0;i<size;i++)
        {
            dp[i]=new int[size]();//初始化，避免读脏数据
        }

        for(int i=size-1;i>=0;i--)
        {
            dp[i][i]=1;
            for(int j=i+1;j<size;j++)
            {
                if(s[i]==s[j])  dp[i][j]=dp[i+1][j-1]+2;
                else
                {
                    dp[i][j]=std::max(dp[i][j-1],dp[i+1][j]);
                }
            }
        }

        int res=dp[0][size-1];
        //释放内存
        for(int i=0;i<size;i++)
        {
            delete[] dp[i];
        }
        delete[] dp;
        return res;
    }
};