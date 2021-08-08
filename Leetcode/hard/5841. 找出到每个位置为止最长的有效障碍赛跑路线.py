"""
你打算构建一些障碍赛跑路线。给你一个 下标从 0 开始 的整数数组 obstacles ，数组长度为 n ，其中 obstacles[i] 表示第 i 个障碍的高度。

对于每个介于 0 和 n - 1 之间（包含 0 和 n - 1）的下标  i ，在满足下述条件的前提下，请你找出 obstacles 能构成的最长障碍路线的长度：

你可以选择下标介于 0 到 i 之间（包含 0 和 i）的任意个障碍。
在这条路线中，必须包含第 i 个障碍。
你必须按障碍在 obstacles 中的 出现顺序 布置这些障碍。
除第一个障碍外，路线中每个障碍的高度都必须和前一个障碍 相同 或者 更高 。
返回长度为 n 的答案数组 ans ，其中 ans[i] 是上面所述的下标 i 对应的最长障碍赛跑路线的长度。
"""


# 贪心+二分查找
class Solution(object):
    def longestObstacleCourseAtEachPosition(self, obstacles):
        """
        :type obstacles: List[int]
        :rtype: List[int]
        """
        n = len(obstacles)
        if n == 0:
            return 0
        minimum_of_len_i = []  # 最长障碍赛跑路线的长度为i+1时，满足条件的序列的末尾最小障碍高度为obstacles[i]
        res=[] # 保存每一个障碍结尾的最长障碍赛跑路线的长度
        for number in obstacles:
            if not minimum_of_len_i or number >= minimum_of_len_i[-1]:
                minimum_of_len_i.append(number)
                res.append(len(minimum_of_len_i))
            else:
                l, r = 0, len(minimum_of_len_i) - 1
                pos = 0
                while l <= r:
                    mid = (l + r) // 2
                    if number >= minimum_of_len_i[mid]:
                        l = mid + 1
                    else:
                        r = mid - 1
                        pos = mid
                minimum_of_len_i[pos] = number
                res.append(pos+1)
        return res