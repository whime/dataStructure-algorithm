"""
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
"""


# 多使用一个列表辅助
# -*- coding:utf-8 -*-
class Solution:
    # 返回[a,b] 其中ab是出现一次的两个数字
    def FindNumsAppearOnce(self, array):
        # write code here
        array.sort()
        arr = []
        for i in range(0, len(array)):
            if array[i] not in arr:
                arr.append(array[i])
            else:
                arr.remove(array[i])
        return arr


# 使用异或
# -*- coding:utf-8 -*-
class Solution:
    # 返回[a,b] 其中ab是出现一次的两个数字
    def FindNumsAppearOnce(self, array):
        # write code here
        res=0
        for i in range(0,len(array)):
            res^=array[i]
        # 查找所有数抑或之后的第一个最低位为1对应的数，则a,b在这一位上也不同
        # 根据这个将整个数组分为两组，一定可以将a,b分开，每个数组再分别异或就可以得到a和
        tag=res&(~res+1)
        a=0
        b=0
        for i in range(0,len(array)):
            if tag & array[i] ==0:
                a^=array[i]
            else:
                b^=array[i]
        return a,b