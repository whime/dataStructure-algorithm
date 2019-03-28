//输入一个链表，反转链表后，输出新链表的表头。
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
    //每两个结点进行如下操作，记录后一个结点的下一个结点tmp，使第二个结点的指针指向第一个结点，以此类推。
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* first;
        ListNode* second;
        ListNode* tmp;
        first=NULL;//最后一个节点的指针要为NULL,不然变成循环链表。
        second=pHead;
        while(second)
        {
            tmp=second->next;
            second->next=first;
            first=second;
            second=tmp;
        }
        return first;
    }
};