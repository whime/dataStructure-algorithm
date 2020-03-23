/**
给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

提示：题目数据保证数组之中任意元素的全部前缀元素和后缀（甚至是整个数组）的乘积都在 32 位整数范围内。
说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。

*/
// 分别累积左右的乘积，再相乘
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size=nums.size();
        vector<int> res(size,1);
        int left=1,right=1;
        for(int i=0;i<size;i++)
        {
            res[i]*=left;
            left*=nums[i];

            res[size-1-i]*=right;
            right*=nums[size-1-i];
        }
        return res;
    }
};