"""
给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
"""


# 先使用快指针和慢指针向前走，直到两者相遇，接着将快指针置于链表头部开始走，
# 此时两个指针速度一致，直到两个指针相等则为入口结点（原理见讨论区推导）

# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def EntryNodeOfLoop(self, pHead):
        # write code here
        if pHead is None or pHead.next is None or pHead.next.next is None:
            return None
        self.fast = pHead.next.next
        self.slow = pHead.next
        while self.fast != self.slow:
            if self.fast.next is not None and self.fast.next.next is not None:
                self.fast = self.fast.next.next
                self.slow = self.slow.next
            else:
                return None
        # 此时self.slow为相遇点
        self.fast = pHead
        while self.fast != self.slow:
            self.fast = self.fast.next
            self.slow = self.slow.next
        return self.slow
