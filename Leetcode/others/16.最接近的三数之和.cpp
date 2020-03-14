/**
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，
使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //先排序，然后使用双指针查找最接近的三个数
        sort(nums.begin(),nums.end());
        if(nums.size()<3)   return 0;
        int closestSum=nums[0]+nums[1]+nums[2];
        int threeSum=0;
        for(int i=0;i<nums.size()-2;i++)
        {
            int left=i+1,right=nums.size()-1;
            while(left<right)
            {
                threeSum=nums[i]+nums[left]+nums[right];
                if(abs(threeSum-target)<abs(closestSum-target))
                {
                    closestSum=threeSum;
                }
                if(target<threeSum) right--;
                else if(target>threeSum)    left++;
                else return target;
            }
        }
        return closestSum;
    }
};