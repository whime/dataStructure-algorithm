/**
给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。
假设只有一个重复的整数，找出这个重复的数。

说明：
不能更改原数组（假设数组是只读的）。
只能使用额外的 O(1) 的空间。
时间复杂度小于 O(n2) 。
数组中只有一个重复的数字，但它可能不止重复出现一次。
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //抽象为环形链表，用快慢指针解决
        int fast=0,slow=0;
        while(true)
        {
            fast=nums[nums[fast]];
            slow=nums[slow];
            if(fast==slow)
            {
                fast=0;
                while(nums[fast]!=nums[slow])
                {
                    fast=nums[fast];
                    slow=nums[slow];
                }
                return nums[slow];
            }
        }
    }
};