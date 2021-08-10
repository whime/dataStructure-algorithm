"""
如果一个数列 至少有三个元素 ，并且任意两个相邻元素之差相同，则称该数列为等差数列。

例如，[1,3,5,7,9]、[7,7,7,7] 和 [3,-1,-5,-9] 都是等差数列。
给你一个整数数组 nums ，返回数组 nums 中所有为等差数组的 子数组 个数。

子数组 是数组中的一个连续序列。
"""


class Solution(object):
    def numberOfArithmeticSlices(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums)<3: return 0
        length=1
        n=len(nums)-1
        difference=nums[1]-nums[0]
        total=0
        for i in range(n):
            if nums[i+1]-nums[i]==difference:
                length+=1
            else:
                if length>=3:
                    total+=((length-1)*(length-2))//2
                length=2
                difference=nums[i+1]-nums[i]
        if length>2:
            total+=((length-1)*(length-2))//2
        return total