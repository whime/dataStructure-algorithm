"""
将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
input:输入一个字符串,包括数字字母符号,可以为空
output:如果是合法的数值表达则返回该数字，否则返回0
"""


# -*- coding:utf-8 -*-
class Solution:
    def StrToInt(self, s):
        # write code here
        res = 0
        negative = False
        mapping = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
        if s == "":
            return 0
        if s[0] == '+' or s[0] == '-':
            negative = True if s[0] == '-' else False
            s = s[1:]
        for alpha in s:
            if '9' >= alpha >= '0':
                res = res * 10 + mapping.index(alpha)
            else:
                return 0
        if res > 0x80000000 and negative:
            return 0
        elif res > 0x7FFFFFFF and not negative:
            return 0
        else:
            return -res if negative else res


if __name__ == '__main__':
    so = Solution()
    print(so.StrToInt('-123'))
