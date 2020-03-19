/**
给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。
注意:
假设字符串的长度不会超过 1010。

eg：
输入:
"abccccdd"
输出:
7
解释:
我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
*/
class Solution {
public:
    int longestPalindrome(string s) {
        int size=s.size();
        map<char,int> mapping;
        for(int i=0;i<size;i++)
        {
            auto iter=mapping.find(s[i]);
            if(iter!=mapping.end())
            {
                iter->second+=1;
            }
            else    mapping[s[i]]=1;
        }
        map<char,int>::iterator iter;
        int res=0;
        for(iter=mapping.begin();iter!=mapping.end();iter++)
        {
            if(iter->second%2==0)   res+=iter->second;//出现偶数次的字符全部取
            else
            {
                res+=iter->second-1;//出现奇数次的字符取少一个
            }
        }
        return res<size?res+1:res;//字符串不都是偶数次字符，可以取一种奇数次字符放在中间，个数加一
    }
};