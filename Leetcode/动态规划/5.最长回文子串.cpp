//给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

//dp方法，时间复杂度O(N^2),空间复杂度O(N^2)
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty())   return s;
        int size=s.size();
        //c++ 定义动态数组有点麻烦
        bool** dp=new bool*[size];
        for(int i=0;i<size;i++)
        {
            dp[i]=new bool[size];
        }
        int left=0,right=0;
        //dp算法，使用size*size的数组保存状态，dp[i][j]表示s[i]~s[j]是否是回文串
        //dp[i][j]=dp[i+1][j-1] &&s[i]==s[j],所以从左下角开始打表
        for(int i=size-1;i>=0;i--)
        {
            dp[i][i]=true;//单个字符视为回文串
            for(int j=i+1;j<size;j++)
            {
                if(s[i]==s[j]&&(j-i==1||dp[i+1][j-1]))
                {
                    dp[i][j]=true;
                }
                else
                    dp[i][j]=false;
                if(dp[i][j]&&j-i>right-left)
                {
                    left=i;
                    right=j;
                }
            }
        }
        return s.substr(left,right-left+1);
    }
};

/**
//中心拓展算法,时间复杂度O(N^2),空间复杂度O(1)
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return s;
        int size=s.length();
        int *res=new int[2]();
        int i=0,left=0,right=0;
        //从左到右遍历，以一段相同字符的序列为中心向左右扩展
        while(i<size)
        {
            left=i,right=i;
            //s[left]~s[right]是中心一段字符相同的序列
            while(right<size-1&&s[right]==s[right+1])    right++;
            i=right+1;
            while(left>0&&right<size-1&&s[left-1]==s[right+1])
            {
                left--;
                right++;
            }
            if(right-left+1>res[1]-res[0]+1)
            {
                res[0]=left;
                res[1]=right;
            }
        }
        return s.substr(res[0],res[1]-res[0]+1);
    }

};
*/
