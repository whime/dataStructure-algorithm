"""
可以用字符串表示一个学生的出勤记录，其中的每个字符用来标记当天的出勤情况（缺勤、迟到、到场）。记录中只含下面三种字符：
'A'：Absent，缺勤
'L'：Late，迟到
'P'：Present，到场
如果学生能够 同时 满足下面两个条件，则可以获得出勤奖励：

按 总出勤 计，学生缺勤（'A'）严格 少于两天。
学生 不会 存在 连续 3 天或 连续 3 天以上的迟到（'L'）记录。
给你一个整数 n ，表示出勤记录的长度（次数）。请你返回记录长度为 n 时，可能获得出勤奖励的记录情况 数量 。答案可能很大，所以返回对 109 + 7 取余 的结果。
"""


class Solution(object):
    def checkRecord(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [[0, 0, 0], [0, 0, 0]]
        dp[0][0] = 1
        mod = 10 ** 9 + 7

        for i in range(n):
            dpNew = [[0,0,0],[0,0,0]]
            # end with 'A'
            for k in range(0, 3):
                dpNew[1][0] = (dpNew[1][0] + dp[0][k]) % mod

            # end with "P"
            for j in range(2):
                for k in range(3):
                    dpNew[j][0]=(dpNew[j][0]+dp[j][k]) % mod

            # end with "L"
            for j in range(2):
                for k in range(1,3):
                    dpNew[j][k]=(dpNew[j][k]+dp[j][k-1]) % mod
            dp=dpNew
        res=0
        for j in range(2):
            for k in range(3):
                res+=dp[j][k]
        return res%mod
