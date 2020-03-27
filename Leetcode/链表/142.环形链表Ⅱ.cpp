/**
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
说明：不允许修改给定的链表。
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
    ListNode *detectCycle(ListNode *head) {
        if(!head||!head->next)  return NULL;
        if(head->next->next==head)  return head;
        ListNode *fast=head,*low=head;
        bool noCycle=true;
        while(fast->next&&fast->next->next)
        {
            low=low->next;
            fast=fast->next->next;
            if(low==fast)
            {
                noCycle=false;
                break;
            }
        }
        if(!noCycle)
        {
            ListNode* p=head;
            while(p!=low)
            {
                p=p->next;
                low=low->next;
            }
            return p;
        }
        else return NULL;
    }
};

//评论区的巧妙解法
//o(n)算法。 堆的地址从低到高，LeetCode的链表内存是顺序申请的，如果有环，head->next一定小于或等于head
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        while(head) {
            if(!less<ListNode *>()(head, head->next)) {
                return head->next;
            }
            head = head->next;
        }
        return nullptr;
    }
};