"""
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。
但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
"""


# -*- coding:utf-8 -*-
class Solution:
    # s字符串
    def isNumeric(self, s):
        # write code here
        import re
        # 牛客的python2不支持 re.fullmatch,会有局部匹配，需要在最后加上$ 限制结尾
        if re.match("[\\+-]?[0-9]*(\\.[0-9]*)?([eE][\\+-]?[0-9]+)?$",s) is not None:
            return True
        else:
            return False


if __name__ == '__main__':
    so=Solution()
    # False
    print(so.isNumeric("12e"))