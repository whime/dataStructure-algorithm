"""
��Ŀ����
��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡���������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}����������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��
"""
# -*- coding:utf-8 -*-
class Solution:
    def MoreThanHalfNum_Solution(self, numbers):
        # write code here

        #��������
        from collections import Counter
        counter=Counter(numbers).most_common()
        #�ж�������һ�����ֵĸ����Ƿ񳬹��������һ�볤��
        if counter[0][1]>len(numbers)/2:
            return counter[0][0]
        else:
            return 0
        
        
        