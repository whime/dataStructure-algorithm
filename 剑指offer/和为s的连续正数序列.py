"""
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他就得到另一
组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数
序列? Good Luck!
output:
输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序
"""
# -*- coding:utf-8 -*-
# 自己的思路，暴力，复杂度太高
class Solution:
    def FindContinuousSequence(self, tsum):
        # write code here
        from copy import deepcopy
        if tsum < 3:
            return []
        resList = []
        tmpList = []
        for num in range(1, tsum // 2 + 2):
            tmpSum = 0
            n = num
            while True:
                if tmpSum < tsum:
                    tmpSum += n
                    tmpList.append(n)
                    n += 1
                elif tmpSum == tsum:
                    print(tmpList)
                    resList.append(deepcopy(tmpList))
                    tmpList = []
                    break
                else:
                    tmpList = []
                    break
        print(resList)
        return resList


class Solution1:
    def FindContinuousSequence(self, tsum):
        # 使用评论区的双指针方法
        from copy import deepcopy
        low = 1
        high = 2
        res = []
        while low < high:
            tmpSum = (high + low) * (high - low + 1) / 2
            if tmpSum == tsum:
                tmpList = []
                for i in range(low, high + 1):
                    tmpList.append(i)
                res.append(deepcopy(tmpList))
                low += 1
            elif tmpSum < tsum:
                high += 1
            else:
                low += 1
        print(res)
        return res


if __name__ == '__main__':
    so = Solution1()
    so.FindContinuousSequence(3)
