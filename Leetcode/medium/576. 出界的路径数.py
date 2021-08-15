"""
给你一个大小为 m x n 的网格和一个球。球的起始坐标为 [startRow, startColumn] 。你可以将球移到在四个方向上相邻的单元格内（可以穿过网格边界到达网格之外）。你 最多 可以移动 maxMove 次球。

给你五个整数 m、n、maxMove、startRow 以及 startColumn ，找出并返回可以将球移出边界的路径数量。因为答案可能非常大，返回对 109 + 7 取余 后的结果。
"""


# 动态规划
class Solution(object):
    def findPaths(self, m, n, maxMove, startRow, startColumn):
        """
        :type m: int
        :type n: int
        :type maxMove: int
        :type startRow: int
        :type startColumn: int
        :rtype: int
        """
        dp=[[0]*n for _ in range(m)]
        dp[startRow][startColumn]=1
        directions=[[0,1],[0,-1],[1,0],[-1,0]]
        res=0
        MOD=1000000007
        for t in range(maxMove):
            dpNew=[[0]*n for _ in range(m)]
            for i in range(m):
                for j in range(n):
                    count=dp[i][j]
                    if count>0:
                        for dir in directions:
                            i1,j1=i+dir[0],j+dir[1]
                            if 0 <= i1 < m and 0 <= j1 < n:
                                dpNew[i1][j1]=(dpNew[i1][j1]+count)%MOD
                            else:
                                res=(res+count)%MOD
            dp=dpNew
        return res
