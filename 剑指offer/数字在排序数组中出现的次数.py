"""
统计一个数字在排序数组中出现的次数。
"""

# -*- coding:utf-8 -*-
class Solution:
    """
    虽然这种暴力的方法可以过，但是评论区一大堆二分查找的
    通常情况下我这种方法是过不了的
    """
    def GetNumberOfK(self, data, k):
        # write code here
        frontIndex=-1
        endIndex=-1
        for i in range(0,len(data)):
            if data[i]==k:
                frontIndex=i
                break
        for i in range(len(data)-1,-1,-1):
            if data[i]==k:
                endIndex=i
                break
        if frontIndex==endIndex==-1:
            return 0
        else:
            return endIndex-frontIndex+1