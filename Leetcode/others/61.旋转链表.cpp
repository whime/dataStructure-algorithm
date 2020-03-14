//给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
/**
输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||!head->next||k==0)   return head;
        ListNode* tmp=head;
        int length=0;//记录链表长度
        while(tmp)
        {
            tmp=tmp->next;
            length++;
        }
        k%=length;//实际需要调转到头部的链表长度
        if(k==0)    return head;//旋转后与原链表相同，直接返回
        int step=length-k-1;
        ListNode* newHead=head;
        while(step--)
        {
            newHead=newHead->next;//查找中间需要断开的部分的前一个节点，也就是新链表的尾节点
        }
        tmp=newHead->next;
        newHead->next=NULL;
        newHead=tmp;
        k--;
        while(k--)
        {
            tmp=tmp->next;
        }
        tmp->next=head;
        return newHead;
    }
};