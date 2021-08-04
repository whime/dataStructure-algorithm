"""
字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。

给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。
"""


# 通常情况下，罗马数字中小的数字在大的数字的右边。
class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        mapping = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        res=0
        i=0
        n=len(s)
        while i<n-1:
            # 罗马数字中小的数字在大的数字的左边，做减法
            if mapping[s[i]]<mapping[s[i+1]]:
                res-=mapping[s[i]]
            else:
                res+=mapping[s[i]]
            i+=1
        return res+mapping[s[-1]]


# 对特殊情况进行条件判断
class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        mapping = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        res=0
        i=0
        n=len(s)
        while i<n:
            if i<n-1:
                if s[i]=='I' and (s[i+1]=='V' or s[i+1]=='X'):
                    res+=mapping[s[i+1]]-mapping[s[i]]
                    i+=2
                elif s[i]=='X' and (s[i+1]=='L' or s[i+1]=='C'):
                    res+=mapping[s[i+1]]-mapping[s[i]]
                    i+=2
                elif s[i]=='C' and (s[i+1]=='D' or s[i+1]=='M'):
                    res+=mapping[s[i+1]]-mapping[s[i]]
                    i+=2
                else:
                    res+=mapping[s[i]]
                    i+=1
            else:
                res+=mapping[s[i]]
                i+=1
        return res