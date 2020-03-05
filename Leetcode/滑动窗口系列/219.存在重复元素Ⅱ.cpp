/**
给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，
使得 nums [i] = nums [j]，并且 i 和 j 的差的绝对值最大为 k。
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int size=nums.size();
        set<int> s;//使用集合保存前k个元素
        for(int i=0;i<size;i++)
        {
            //如果检索到的元素在集合中返回真
            if(s.find(nums[i])!=s.end())
                return true;
            s.insert(nums[i]);

            if(s.size()==k+1)
                s.erase(nums[i-k]);
        }
        return false;
    }
};