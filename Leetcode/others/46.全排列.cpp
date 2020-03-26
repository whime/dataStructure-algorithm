//给定一个 没有重复 数字的序列，返回其所有可能的全排列。
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int n=nums.size();
        backtrack(nums,res,n,0);
        return res;
    }
    void backtrack(vector<int>& nums,vector<vector<int>>& res,int n,int first)
    {
        if(n==first)    res.push_back(nums);
        for(int i=first;i<n;i++)
        {
            swap(nums[first],nums[i]);
            backtrack(nums,res,n,first+1);
            swap(nums[i],nums[first]);
        }
    }
};