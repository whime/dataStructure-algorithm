"""
给定一个正整数 n，找出小于或等于 n 的非负整数中，其二进制表示不包含 连续的1 的个数。
"""


class Solution(object):
    def findIntegers(self, n):
        """
        :type n: int
        :rtype: intbit_size=n.bit_length
        """
        dp = [0] * 31
        dp[0] = dp[1] = 1
        for i in range(2, 31):
            dp[i] = dp[i - 1] + dp[i - 2]

        res, pre = 0, 0
        for i in range(29, -1, -1):
            mask = 1 << i
            if mask & n:
                res += dp[i + 1]
                if pre:
                    break
                pre = 1
            else:
                pre = 0
            if i == 0:
                res += 1
        return res


if __name__ == '__main__':
    so=Solution()
    so.findIntegers(9)