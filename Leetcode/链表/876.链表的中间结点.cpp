/**
给定一个带有头结点 head 的非空单链表，返回链表的中间结点。

如果有两个中间结点，则返回第二个中间结点。
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//很简单的一道题，还是花了十分钟一次ac,看了评论区初始化快慢指针都是指向第一个结点，根本不需要后面的if语句判断。
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(!head||!head->next)  return head;
        ListNode *front=head,*rear=head->next;
        while(rear&&rear->next)
        {
            front=front->next;
            rear=rear->next->next;
        }
        if(rear)    return front->next;
        return front;
    }
};