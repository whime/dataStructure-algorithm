"""
输入两个链表，找出它们的第一个公共结点。
"""

# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    """
    来源讨论区：
    找出2个链表的长度，然后让长的先走两个链表的长度差，然后再一起走
    （因为2个链表用公共的尾部）
    """
    def FindFirstCommonNode(self, pHead1, pHead2):
        # write code here
        length1=self.calLength(pHead1)
        length2=self.calLength(pHead2)
        if length1>length2:
            pHead1=self.goThroughLinkList(pHead1,length1-length2)
        else:
            pHead2=self.goThroughLinkList(pHead2,length2-length1)
        while pHead1 is not None:
            if pHead1.val==pHead2.val:
                return pHead1
            pHead1=pHead1.next
            pHead2=pHead2.next
        return None


    def calLength(self,head):
        length=1
        while head:
            head=head.next
            length+=1
        return length
    def goThroughLinkList(self,head,steps):
        for i in range(0,steps):
            head=head.next
        return head
