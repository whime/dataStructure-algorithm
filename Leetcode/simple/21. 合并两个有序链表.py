"""
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
"""

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if l1==None:return l2
        if l2==None:return l1
        curNode=l1
        headNode=ListNode(0,l2)
        right=headNode
        while curNode!=None:
            v=curNode.val
            while True:
                if right.next and right.next.val<v:
                    right=right.next
                else:
                    break
            tmpNode=curNode.next
            curNode.next=right.next
            right.next=curNode
            right=curNode
            curNode=tmpNode

            if not right.next:
                break
        if not right.next:
            right.next=curNode
        return headNode.next
