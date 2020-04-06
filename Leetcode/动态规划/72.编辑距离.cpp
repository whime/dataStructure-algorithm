/**
给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：
插入一个字符
删除一个字符
替换一个字符
*/
//两行数组，类似于最长公共子串，初始状态和转换方程有差别。
class Solution {
public:
    int minDistance(string word1, string word2) {
        int size2=word2.size();
        int size1=word1.size();
        int *pre=new int[size2+1]();
        int *dp=new int[size2+1]();
        int *tmp;

        for(int i=0;i<=size2;i++)
        {
            pre[i]=i;
        }
        for(int i=1;i<=size1;i++)
        {
            dp[0]=i;
            for(int j=1;j<=size2;j++)
            {
                if(word2[j-1]==word1[i-1])  dp[j]=pre[j-1];
                else    dp[j]=min(min(pre[j-1],dp[j-1]),pre[j])+1;
            }
            tmp=dp;
            dp=pre;
            pre=tmp;
        }
        int res=pre[size2];//最后结果在pre的最后一个元素
        delete[] pre;
        delete[] dp;
        return res;

    }
};