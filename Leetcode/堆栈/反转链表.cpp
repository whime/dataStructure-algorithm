/**
反转一个单链表.
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
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
    ListNode* reverseList(ListNode* head) {
        //迭代法
        // ListNode* pre=NULL;
        // ListNode* cur=head;
        // while(cur!=NULL)
        // {
        //     ListNode* tmp=cur->next;
        //     cur->next=pre;
        //     pre=cur;
        //     cur=tmp;
        // }
        // return pre;

        //递归
        if(head==NULL||head->next==NULL) return head;
        ListNode* p=reverseList(head->next);

        head->next->next=head;//将指向反置
        head->next=NULL;
        return p;//一直返回的p就是队尾元素
    }

};