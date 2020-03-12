/**
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。
注意：答案中不可以包含重复的三元组。
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int left,right;
        vector<vector<int>> res;
        int sum=0;
        //先排好序，在每个nums[i]后面使用双指针查找满足条件的两个数
        for(int i=0;i<nums.size();i++)
        {
            if(i>0&&nums[i]==nums[i-1]) continue;
            if(nums[i]>0)   break;//若nums[i]>0,其后面都是大于0，不可能有满足条件的数

            left=i+1;
            right=nums.size()-1;
            while(left<right)
            {
                sum=nums[i]+nums[left]+nums[right];
                if(sum==0)
                {
                    res.push_back({nums[i],nums[left],nums[right]});
                    //去重
                    while(left<right&&nums[left]==nums[left+1]) left++;
                    while(left<right&&nums[right]==nums[right-1]) right--;
                    left++;
                    right--;
                }
                else if(sum>0)  right--;
                else left++;
            }
        }
        return res;
    }
};