"""
给定一个整数数组 prices，其中第 i 个元素代表了第 i 天的股票价格 ；整数 fee 代表了交易股票的手续费用。

你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。

返回获得利润的最大值。

注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。
"""


# python版本O(N^2),TLE
# class Solution(object):
#     def maxProfit(self, prices, fee):
#         """
#         :type prices: List[int]
#         :type fee: int
#         :rtype: int
#         """
#         if prices is None or len(prices)==0:
#             return 0
#         n = len(prices)
#         dp = [0]*n
#         for i in range(1,n):
#             dp[i]=dp[i-1]
#             for j in range(i-1,-1,-1):
#                 singleProfit = max(prices[i]-prices[j]-fee,0)
#                 if j-1>=0:
#                     dp[i]=max(dp[i],dp[j-1]+singleProfit)
#                 else:
#                     dp[i]=max(dp[i],singleProfit)
#         return dp[n-1]

class Solution(object):
    def maxProfit(self, prices, fee):
        """
        :type prices: List[int]
        :type fee: int
        :rtype: int
        """
        # dp[i] = max(dp[i-1],max(prices[i]-prices[j]-fee+dp[j-1]))
        # dp[i]=dp[i-1]
        # dp[i]=max(dp[i],xxx),xxx=prices[i]-prices[j]-fee+dp[j-1]
        # xxx = prices[i]-fee-min(prices[j]-dp[j-1])
        n = len(prices)
        if n == 0:
            return 0
        dp = [0] * n
        minBefore = prices[0]
        for i in range(1,n):
            dp[i]=dp[i-1]
            dp[i] = max(dp[i],prices[i]-fee-minBefore)
            minBefore = min(prices[i]-dp[i-1],minBefore)
        return dp[n-1]

