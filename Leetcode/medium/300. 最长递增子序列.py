"""
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。
"""


# 动态规划
# class Solution(object):
#     def lengthOfLIS(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: int
#         """
#         n = len(nums)
#         dp = [1] * n
#         for i in range(1, n):
#             for j in range(0, i):
#                 if nums[i] > nums[j]:
#                     dp[i] = max(dp[i], dp[j] + 1)
#         return max(dp)


# 贪心+二分查找
class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n == 0:    return 0
        minimum_of_len_i = []  # 长度为i时的最长递增子序列的满足条件的末尾最小元素
        for number in nums:
            if not minimum_of_len_i or number > minimum_of_len_i[-1]:
                minimum_of_len_i.append(number)
            else:
                l, r = 0, len(minimum_of_len_i) - 1
                pos = 0
                while l <= r:
                    mid = (l + r) // 2
                    if number > minimum_of_len_i[mid]:
                        l = mid + 1
                    else:
                        r = mid - 1
                        pos = mid
                minimum_of_len_i[pos] = number
        return len(minimum_of_len_i)


if __name__ == '__main__':
    so=Solution()
    so.lengthOfLIS([0,1,0,3,2,3])