# -*- coding:utf-8 -*-
"""
输入一个递增排序的数组和一个数字S，在数组中查找两个数，
使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
output:
对应每个测试案例，输出两个数，小的先输出。
"""

class Solution:
    def FindNumbersWithSum(self, array, tsum):
        # 复杂度O（n^2)
        for num in array:
            for num2 in array[::-1]:
                if num+num2==tsum:
                    return num,num2
        return []


class Solution1:
    def FindNumbersWithSum(self, array, tsum):
        # 复杂度O(n)
        low,high= 0,len(array)-1
        while low<high:
            if array[low]+array[high]== tsum:
                return array[low],array[high]
            elif array[low]+array[high]<tsum:
                low+=1
            else:
                high-=1
        return []