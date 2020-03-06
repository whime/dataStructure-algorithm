/**
给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //先使用快慢指针找中点，然后将后半部分逆转，插入到前半部分中
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head||!head->next)  return;
        ListNode *slow=head,*fast=head;
        //快慢指针找中点
        while(fast&&fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        //反转，后半部分长度应小于等于前半部分，便于插入
        ListNode* SecondHead=doReverse(slow->next);
        slow->next=NULL;

        //后半部分插入到前半部分的间隙里
        ListNode *p1=head,*p2=SecondHead,*tmp2;
        while(p1&&p2)
        {
            tmp2=p2->next;
            p2->next=p1->next;
            p1->next=p2;
            p1=p2->next;
            p2=tmp2;
        }

    }

    //反转链表
    ListNode* doReverse(ListNode* head)
    {
        ListNode *pre=NULL,*cur=head,*tmp;
        while(cur)
        {
            tmp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=tmp;
        }
        return pre;
    }
};