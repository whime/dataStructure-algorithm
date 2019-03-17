/*
题目描述
输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
*/

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
//使用栈
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> value;
		stack<int> st;
		ListNode* p = head;
		while (p)
		{
			st.push(p->val);
			p = p->next;
		}
		while (!st.empty())
		{
			value.push_back(st.top());
			st.pop();
		}
		return value;
	}
};

//递归方法
class Solution {
public:
	vector<int> value;
	vector<int> printListFromTailToHead(ListNode* head) {

		ListNode* p = head;
		if (p != NULL)
		{
			if (p->next != NULL)
				printListFromTailToHead(p->next);
			value.push_back(p->val);
		}
		return value;
	}
};