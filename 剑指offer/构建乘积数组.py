"""
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
"""


# -*- coding:utf-8 -*-
class Solution:
    def multiply(self, A):
        # 时间复杂度O(n)，来自讨论区
        B=[]
        B.append(1)
        for i in range(1,len(A)):
            B.append(B[i-1]*A[i-1])
            print(B)
        tmp=1
        for j in range(len(A)-2,-1,-1):
            tmp*=A[j+1]
            B[j]*=tmp
        return B


if __name__ == '__main__':
    so = Solution()
    # print(so.multiply([1,2,3]))
    so.multiply([1, 2, 3])