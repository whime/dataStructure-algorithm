class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        """
        dp[i] = max(dp[i-1],prices[i]-prices[j]+dp[j-2])
        dp[i] = dp[i-1]
        =>max(-prices[j]+dp[j-2]),j<i
        """
        if len(prices)==0:
            return 0
        n = len(prices)
        dp = [0]*n
        maxBefore = -prices[0]
        for i in range(1,n):
            dp[i] = max(dp[i-1],prices[i]+maxBefore)
            if i>=2:
                maxBefore = max(maxBefore, dp[i-2]-prices[i])
            else:
                maxBefore = max(maxBefore,-prices[i])
        return dp[n-1]