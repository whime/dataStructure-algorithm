/**
给定一个整数数组，判断是否存在重复元素。
如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        int size=nums.size();
        for(int i=0;i<size;i++)
        {
            if(s.find(nums[i])!=s.end())
                return true;
            s.insert(nums[i]);
        }
        return false;
    }
};