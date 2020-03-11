/**
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> indexmap;
        int tmp;
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            tmp=target-nums[i];
            if(indexmap.find(tmp)!=indexmap.end())
            {
                res.push_back(indexmap[tmp]);
                res.push_back(i);
                return res;
            }
            // indexmap.insert(map<int,int>::value_type(nums[i],i));
            indexmap[nums[i]]=i;
        }
        return res;
    }
};