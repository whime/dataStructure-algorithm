//给定一个可包含重复数字的序列，返回所有不重复的全排列。
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int n=nums.size();
        permute(nums,res,0,n);
        return res;
    }
    void permute(vector<int> nums,vector<vector<int>>& res,int first,int n)
    {
        if(first==n)
            res.push_back(nums);
        for(int i=first;i<n;i++)
        {
            if(i!=first&&nums[i]==nums[first])    continue;
            swap(nums[first],nums[i]);
            permute(nums,res,first+1,n);
        }
    }
};