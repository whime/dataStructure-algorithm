"""
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
"""


# -*- coding:utf-8 -*-
class Solution:
    def Add(self, num1, num2):
        # 使用与运算判断进位，异或运算模拟不带进位的加法
        carry = ((num1 & num2) << 1) & 0xFFFFFFFF
        addSum = (num1 ^ num2) & 0xFFFFFFFF
        while carry:
            # 由于python能够存储无限位长整型，使用0xFFFFFFFF进行边界处理，避免死循环
            tmp = (addSum ^ carry) & 0xFFFFFFFF
            carry = ((addSum & carry) << 1) & 0xFFFFFFFF
            addSum = tmp
        # 若是溢出则需要转为相应负数的补码，参考https://blog.csdn.net/lrs1353281004/article/details/87192205
        return addSum if addSum <= 0x7FFFFFFF else ~(addSum ^ 0xFFFFFFFF)


if __name__ == '__main__':
    so = Solution()
    print(so.Add(3, 5))
