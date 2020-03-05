//给定一个字符串，请你找出其中不含有重复字符的 最长子串的长度。
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int right=-1;
        int freq[256]={0};//保存256个字符出现的次数
        int res=0;
        int size=s.size();
        while(left<size)
        {
            //若使用right<size-1,会出现类型提升问题，right将转换为无符号数
            if(right+1<size&&freq[s[right+1]]==0)
            {
                //若还没有出现重复字符，向右移动
                right++;
                freq[s[right]]++;
            }
            else
            {
                //左边界右移
                freq[s[left]]--;
                left++;
            }
            //记录窗口的最大值
            if(res<(right-left+1))  res=right-left+1;
        }
        return res;
    }
};