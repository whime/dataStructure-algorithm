/**
给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列。
一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列。
若这两个字符串没有公共子序列，则返回 0。
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int size1=text1.size();
        int size2=text2.size();
        int **res=new int*[size1+1];

        //需要构造(size1+1)*(size2+1)大小的矩阵，第0行第0列都为零
        for(int i=0;i<=size1;i++)
        {
            res[i]=new int[size2+1]();
        }

        for(int i=1;i<=size1;i++)
        {
            for(int j=1;j<=size2;j++)
            {
                if(text1[i-1]==text2[j-1])  res[i][j]=res[i-1][j-1]+1;
                else if(res[i][j-1]>=res[i-1][j])   res[i][j]=res[i][j-1];
                else res[i][j]=res[i-1][j];
            }
        }
        return res[size1][size2];
    }
};

/**评论区的一维数组python解法
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        n1, n2 = len(text1), len(text2)
        pre = [0 for _ in range(n2 + 1)]
        dp = [0 for _ in range(n2 + 1)]
        for i in range(n1):
            for j in range(1, n2 + 1):
                if text1[i] == text2[j-1]:
                    dp[j] = pre[j-1] + 1
                else:
                    dp[j] = max(pre[j], dp[j-1])
                pre[j-1] = dp[j-1]
            pre[j] = dp[j]
        return dp[-1]
*/