/**
假设按照升序排序的数组在预先未知的某个点上进行了旋转。
( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
你可以假设数组中不存在重复的元素。
你的算法时间复杂度必须是 O(log n) 级别。
*/

//使用二分查找，每次计算middle将数组分为一段有序和部分有序的两部分，在有序的数组范围里进行判断
//如果存在有序数组里则是一般的二分搜索了，如果不在则在另一段部分有序的数组重复执行上述过程。
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        int middle;
        while(left<=right)
        {
            middle=(left+right)/2;
            if(nums[middle]==target)    return middle;
            if(nums[left]<=nums[middle])
            {
                if(nums[left]<=target&&nums[middle]>target)  right=middle-1;
                else    left=middle+1;
            }
            else
            {
                if(nums[middle]<target&&nums[right]>=target)    left=middle+1;
                else    right=middle-1;
            }
        }
        return -1;
    }
};