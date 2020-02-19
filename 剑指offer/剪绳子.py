'''
给你一根长度为n的绳子，请把绳子剪成整数长的m段（m、n都是整数，n>1并且m>1），
每段绳子的长度记为k[0],k[1],...,k[m]。请问k[0]xk[1]x...xk[m]可能的最大乘积是多少？
例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
'''
# -*- coding:utf-8 -*-
class Solution:
    # 动态规划
    def cutRope(self, number):
        if number<2:
            return 0
        elif number==2:
            return 1
        elif number==3:
            return 2
        dp=[0,1,2,3]
        for i in range(4,number+1):
            maxnum=0
            for j in range(1,i//2+1):
                multiRes=dp[j]*dp[i-j]
                if multiRes>maxnum:
                    maxnum=multiRes
            dp.append(maxnum)
        return dp[number]


'''
# 贪心算法，尽可能分成长度为3的段
# -*- coding:utf-8 -*-
class Solution:
    def cutRope(self, number):
        if number<2:
            return 0
        elif number==2:
            return 1
        elif number==3:
            return 2
        if number%3==0:
            return 3**(number//3)
        elif number%3==1:
            return 4*3**(number//3-1)
        else:return 2*3**(number//3)

'''