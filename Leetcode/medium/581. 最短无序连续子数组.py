"""
给你一个整数数组 nums ，你需要找出一个 连续子数组 ，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。

请你找出符合题意的 最短 子数组，并输出它的长度。
"""


class Solution(object):
    def findUnsortedSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums)<2:
            return 0
        n=len(nums)
        front=None
        rear=None
        minimum = float("inf")
        maximum = float("-inf")
        for i in range(0,n):
            if nums[i]<maximum:
                rear = i
            else:
                maximum = nums[i]
            if nums[n-1-i] <= minimum:    # mind the equal state
                minimum = nums[n-1-i]
            else:
                front = n-1-i
        return rear-front+1 if rear is not None else 0
