"""
题目描述
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007
题目保证输入的数组中没有的相同的数字

数据范围：

对于%50的数据,size<=10^4

对于%75的数据,size<=10^5

对于%100的数据,size<=2*10^5
"""

"""
使用插入排序，边找插入的地方边计算左边大于插入值的数的个数。
下面两个方法估计是没问题的，第二种方法使用折半查找找插入位置还超时。
只能说python不适合做这道题目
"""


# -*- coding:utf-8 -*-
class Solution:
    def InversePairs(self, data):
        # 这个写的有点乱了，不看也罢
        count = 0
        for i in range(1, len(data)):
            middle = i // 2
            end = i
            while data[middle] > data[i]:
                count += end - middle
                if end == 0:
                    data.insert(0, data[i])
                    del data[i + 1]
                    break
                end = middle
                middle //= 2
            if end == 0: continue
            j = 0
            for j in range(end - 1, middle - 1, -1):
                if data[j] > data[i]:
                    count += 1
                else:
                    break
            data.insert(j + 1, data[i])
            del data[i + 1]
            # print(i,data[:10])
        return count % 1000000007


class Solution1:
    def InversePairs(self, data):
        # 插入排序，使用折半查找确定插入位置
        count = 0
        for i in range(1, len(data)):
            front = 0
            end = i
            middle = i // 2
            while front != middle:
                if data[middle] > data[i]:
                    end = middle
                else:
                    front = middle
                middle = (front + end) // 2
            if data[front] > data[i]:
                # front=middle=end-1的情况，data[front]也大于插入值
                count += (i - front)
                data.insert(front, data[i])
            else:
                # front=middle=end-1的情况，data[front]小于插入值
                count += (i - front) - 1
                data.insert(end, data[i])
            del data[i + 1]

        return count % 1000000007


if __name__ == '__main__':
    so = Solution()
    print(so.InversePairs(
        [364, 637, 341, 406, 747, 995, 234, 971, 571, 219, 993, 407, 416, 366, 315, 301, 601, 650, 418, 355, 460, 505,
         360, 965, 516, 648, 727, 667, 465, 849, 455, 181, 486, 149, 588, 233, 144, 174, 557, 67, 746, 550, 474, 162,
         268, 142, 463, 221, 882, 576, 604, 739, 288, 569, 256, 936, 275, 401, 497, 82, 935, 983, 583, 523, 697, 478,
         147, 795, 380, 973, 958, 115, 773, 870, 259, 655, 446, 863, 735, 784, 3, 671, 433, 630, 425, 930, 64, 266, 235,
         187, 284, 665, 874, 80, 45, 848, 38, 811, 267, 575]))
