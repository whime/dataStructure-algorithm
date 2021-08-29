"""
给你一个正整数数组 arr ，请你计算所有可能的奇数长度子数组的和。

子数组 定义为原数组中的一个连续子序列。

请你返回 arr 中 所有奇数长度子数组的和 。
"""


class Solution(object):
    def sumOddLengthSubarrays(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        n=len(arr)
        loop=(n+1)//2
        res=0
        step=1
        for i in range(loop):
            for j in range(n-step+1):
                res+=sum(arr[j:j+step])
            step+=2
        return res