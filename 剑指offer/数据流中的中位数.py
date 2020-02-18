'''
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。
'''

# -*- coding:utf-8 -*-
'''插入一次sort一次。。

class Solution:
    source = []

    def Insert(self, num):
        # write code here
        self.source.append(num)
        self.source.sort()

    def GetMedian(self, s):
        # write code here
        length = len(self.source)
        if length % 2 == 0:
            return (self.source[length // 2] + self.source[length // 2 - 1]) / 2.0
        return self.source[length // 2]
'''

'''
使用原生heapy模块实现的最小堆排序，最大堆使用取相反数插入最小堆代替
'''
# -*- coding:utf-8 -*-
import heapq
class Solution:
    def __init__(self):
        self.highHeap = []
        self.lowHeap = []
        self.count = 0

    def Insert(self, num):
        # write code here
        self.count += 1
        if self.count & 1:
            # 第奇数个数据，若最小堆堆顶元素小于num,将num插入最小堆，最小堆堆顶元素插入最大堆，
            # 否则直接插入最大堆
            if len(self.lowHeap) != 0 and self.lowHeap[0] < num:
                heapq.heappush(self.lowHeap, num)
                num = heapq.heappop(self.lowHeap)
            heapq.heappush(self.highHeap, -num)
        else:
            # 第偶数个数据，若最大堆堆顶元素大于num,将num插入最大堆，最大堆堆顶元素插入最小堆，
            # 否则直接插入最小堆
            if len(self.highHeap) != 0 and self.highHeap[0] < -num:
                heapq.heappush(self.highHeap, -num)
                num = -heapq.heappop(self.highHeap)
            heapq.heappush(self.lowHeap, num)

    def GetMedian(self, s):
        if self.count & 1:
            return -self.highHeap[0]
        else:
            return (self.lowHeap[0] - self.highHeap[0]) / 2.0