"""
给你一个数组 nums 。数组「动态和」的计算公式为：runningSum[i] = sum(nums[0]…nums[i]) 。

请返回 nums 的动态和。
"""


# class Solution(object):
#     def runningSum(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: List[int]
#         """
#         res=[]
#         n=len(nums)
#         tmpSum=sum(nums)
#         res.append(tmpSum)
#         for number in nums[n-1:0:-1]:
#             tmpSum-=number
#             res.append(tmpSum)
#         res.reverse()
#         return res


class Solution(object):
    def runningSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        for i in range(1,len(nums)):
            nums[i]+=nums[i-1]
        return nums