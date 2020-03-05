//给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组。如果不存在符合条件的连续子数组，返回 0。
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int size=nums.size();
        int left=0,right=-1;
        int sum=0,res=size+1;
        //双指针，滑动窗口
        while(left<size)
        {
            if(right+1<size&&sum<s)
            {
                right++;
                sum+=nums[right];
            }
            else
            {
                sum-=nums[left];
                left++;
            }
            if(sum>=s)
            {
                res=res>(right-left+1)?(right-left+1):res;
            }
        }

        if(res!=size+1) return res;
        return 0;
    }
};