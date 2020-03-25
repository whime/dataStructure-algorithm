/**
你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。
同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        //两次dp，一次不考虑最后一个元素，一次不考虑第一个元素
        int size=nums.size();
        if(size==0) return 0;
        if(size==1) return nums[0];
        int a=0,b=0,c;
        for(int i=0;i<size-1;i++)
        {
            c=max(a+nums[i],b);
            a=b;
            b=c;
        }
        int res=b;
        a=0;b=0;
        for(int i=1;i<size;i++)
        {
            c=max(a+nums[i],b);
            a=b;
            b=c;
        }
        return max(res,b);
    }
};