"""
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）
"""


# -*- coding:utf-8 -*-
class Solution:
    def Sum_Solution(self, n):
        # 讨论区一个递归解法,主要利用逻辑与结束递归
        return n and n + self.Sum_Solution(n - 1)
        # 使用sum函数
        # return sum(list(range(n+1)))
