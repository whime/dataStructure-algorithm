"""
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
"""


class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        n = len(prices)
        # dp[i] 表示在i 时间点或之后买入第二笔交易的最大利润
        maxProfit = 0
        dp = [0]*n
        maxSell = prices[n-1]
        for i in range(n-2,-1,-1):
            dp[i] = max(dp[i+1],maxSell-prices[i])
            maxSell = max(maxSell,prices[i])
            maxProfit = max(maxProfit,dp[i])

        # 枚举第一笔交易的卖出时间点i，第一笔交易的最大利润等于prices[i]-min(prices[0~i-1])
        # 第二笔交易的最大利润则为在i+1时间点或之后买入的最大利润dp[i+1]
        minBuy = prices[0]
        for i in range(1,n-1):
            maxProfit = max(dp[i+1]+prices[i]-minBuy,maxProfit)
            minBuy = min(minBuy,prices[i])

        return maxProfit
