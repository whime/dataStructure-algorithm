/**
一个有名的按摩师会收到源源不断的预约请求，每个预约都可以选择接或不接。在每次预约服务之间要有休息时间，因此她不能接受相邻的预约。
给定一个预约请求序列，替按摩师找到最优的预约集合（总预约时间最长），返回总的分钟数。

*/
//典型的dp
class Solution {
public:
    int massage(vector<int>& nums) {
        int size=nums.size();
        if(size==0) return 0;
        if(size==1) return nums[0];

        vector<int> dp;
        dp.push_back(nums[0]);
        dp.push_back(max(nums[0],nums[1]));
        for(int i=2;i<size;i++)
        {
            dp.push_back(max(dp[i-2]+nums[i],dp[i-1]));
        }
        return dp[size-1];
    }
};