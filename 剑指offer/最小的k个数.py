"""
��Ŀ����
����n���������ҳ�������С��K��������������4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4��
"""
# -*- coding:utf-8 -*-
class Solution:
    def GetLeastNumbers_Solution(self, tinput, k):
        # write code here
        tinput=list(set(tinput))
        if k>len(tinput):
            return []
        arr=sorted(tinput)[0:k]
        return arr