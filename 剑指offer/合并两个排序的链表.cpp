//输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
#include<iostream>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		ListNode* tmp=new ListNode(0);
		ListNode* head = tmp;
		while (pHead1 != NULL && pHead2 != NULL)
		{
			if (pHead1->val >= pHead2->val)
			{
				tmp->next = pHead2;
				pHead2 = pHead2->next;
			}
			else
			{
				tmp->next = pHead1;
				pHead1 = pHead1->next;
			}
			tmp = tmp->next;
		}
		if (pHead1 == NULL)    tmp->next = pHead2;
		if (pHead2 == NULL)    tmp->next = pHead1;
		return head->next;

	}
};
int main()
{
	Solution so = Solution();
	struct ListNode * list1 = new struct ListNode(1);
	struct ListNode * list2 = new struct ListNode(2);
	struct ListNode * tmp = list1;
	for (int i =3; i < 9; i+=2)
	{
		tmp->next = new struct ListNode(i);
		tmp = tmp->next;
	}
	tmp = list2;
	for (int j = 4; j < 10; j += 2)
	{
		tmp->next = new struct ListNode(j);
		tmp = tmp->next;
	}
	struct ListNode* result = so.Merge(list1, list2);
	while (result)
	{
		cout << result->val << " ";
		result = result->next;

	}
	system("pause");

}