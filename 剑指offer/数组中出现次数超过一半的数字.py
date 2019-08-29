"""
题目描述
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
"""
# -*- coding:utf-8 -*-
class Solution:
    def MoreThanHalfNum_Solution(self, numbers):
        # write code here

        #讨论区答案
        from collections import Counter
        counter=Counter(numbers).most_common()
        #判断数量第一的数字的个数是否超过了数组的一半长度
        if counter[0][1]>len(numbers)/2:
            return counter[0][0]
        else:
            return 0
        
        
        