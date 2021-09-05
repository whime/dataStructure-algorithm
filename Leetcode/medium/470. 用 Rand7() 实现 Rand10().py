"""
已有方法 rand7 可生成 1 到 7 范围内的均匀随机整数，试写一个方法 rand10 生成 1 到 10 范围内的均匀随机整数。

不要使用系统的 Math.random() 方法。
"""


# The rand7() API is already defined for you.
# def rand7():
# @return a random integer in the range 1 to 7

class Solution(object):
    def rand10(self):
        """
        :rtype: int
        """
        first,second=0,0
        while True:
            first = rand7()
            if first<=6:
                break
        while True:
            second=rand7()
            if second<=5:
                break
        return second if first%2==1 else second+5


# 拒绝采样法
class Solution(object):
    def rand10(self):
        """
        :rtype: int
        """
        while True:
            a=rand7()
            b=rand7()
            idx=(a-1)*7+b
            if idx<=40:
                return 1+idx%10
            a=idx-40
            b=rand7()
            # idx range in 1-63
            idx= (a-1)*7+b
            if idx<=60:
                return idx%10+1
            a=idx-60
            b=rand7()
            # idx range in 1-21
            idx=(a-1)*7+b
            if idx<=20:
                return idx%10+1