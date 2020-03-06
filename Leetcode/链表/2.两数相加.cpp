/**
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照逆序的方式存储的，并且它们的每个节点只能存储一位数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //使用迭代，基本不用算法，还是不够简洁啊。
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0,tmp;
        ListNode* res=new ListNode(0);
        ListNode* head=res;
        while(l1&&l2)
        {
            head->next=new ListNode(0);
            head=head->next;

            tmp=carry+l1->val+l2->val;
            head->val=tmp%10;
            carry=tmp/10;

            l1=l1->next;
            l2=l2->next;
        }

        ListNode* L=(l1==NULL?l2:l1);
        while(L)
        {
            tmp=carry+L->val;
            head->next=new ListNode(tmp%10);
            carry=tmp/10;
            head=head->next;
            L=L->next;
        }
        if(carry!=0)
        {
            head->next=new ListNode(carry);
            head->next->next=NULL;
        }
        else head->next=NULL;

        return res->next;
    }
};