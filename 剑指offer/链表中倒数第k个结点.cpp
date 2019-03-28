//输入一个链表，输出该链表中倒数第k个结点。
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode* head=pListHead;
        ListNode* last=head;
        unsigned int i;
        //很巧妙的思路，c++空指针是NULL,全是大写，老是和python,java搞混
        for(i=0;last!=NULL;i++)
        {
            if(i>=k)
            {
                //last指针跑到第k步时，head指针也开始跑
                head=head->next;
            }
            last=last->next;
        }
        return i>=k?head:NULL;
    }
};