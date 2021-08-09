"""
超级丑数 是一个正整数，并满足其所有质因数都出现在质数数组 primes 中。

给你一个整数 n 和一个整数数组 primes ，返回第 n 个 超级丑数 。

题目数据保证第 n 个 超级丑数 在 32-bit 带符号整数范围内。
"""


# 最小堆
class Solution(object):
    def nthSuperUglyNumber(self, n, primes):
        """
        :type n: int
        :type primes: List[int]
        :rtype: int
        """
        import heapq
        uglySet={1}
        smallheap=[1]
        for i in range(n):
            ugly = heapq.heappop(smallheap)
            for prime in primes:
                next=prime*ugly
                if next not in uglySet:
                    uglySet.add(next)
                    heapq.heappush(smallheap,next)
        return ugly

