"""
给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
"""


class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        n=len(nums)
        if n==0:
            return 0
        index=0
        modifyIndex=-1
        count=0
        while True:
            if nums[index]==val:
                count+=1
                if modifyIndex==-1:
                    modifyIndex=index
            elif modifyIndex!=-1:
                nums[modifyIndex]=nums[index]
                modifyIndex+=1
            index+=1
            if index>=n:
                break
        return n-count
