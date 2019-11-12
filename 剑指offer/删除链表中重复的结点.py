"""
题目描述
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，
返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
"""


# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def deleteDuplication(self, pHead):
        # write code here
        if pHead is None or pHead.next is None:
            return pHead
        front = pHead
        rear = pHead.next
        # 标志位，是否出现过重复结点
        flag = False
        # 去除前面的重复节点，如1->1->2->2->3->4前面的1->1->2->2
        while front.val == rear.val:
            front = front.next
            rear = rear.next
            flag = True
            if rear is None:
                return None
        if flag:
            # 出现重复节点，去除
            pHead = front = rear
            rear = rear.next
            flag = False
            if rear is None:
                return pHead
            if front.val == rear.val:
                # 还有前置的重复结点，继续处理
                return self.deleteDuplication(front)
        else:
            # 前置的重复结点处理完毕，处理在中间和尾部的重复结点
            pHead = front

        while rear.next is not None:
            while rear.val == rear.next.val:
                rear = rear.next
                flag = True
                if rear.next is None:
                    front.next = None
                    return pHead
            else:
                if flag:
                    # 去除front 和 rear之间的重复结点
                    rear = rear.next
                    front.next = rear
                    flag = False
                else:
                    # 没有出现重复结点，各移一位
                    rear = rear.next
                    front = front.next
        return pHead


"""
设置头结点更好处理
class Solution:
    def deleteDuplication(self, pHead):
        # write code here
        if pHead is None or pHead.next is None:return pHead
        pNode=ListNode(0)
        pNode.next=pHead
        front=pNode
        rear=pNode.next
        
        while rear is not None:
            if rear.next is not None and rear.val==rear.next.val:
                while rear.next is not None and rear.val==rear.next.val:
                    rear=rear.next
                rear=rear.next
                front.next=rear
            else:
                front=front.next
                rear=rear.next
        return pNode.next
        
"""