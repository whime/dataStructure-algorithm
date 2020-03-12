//请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点，你将只被给定要求被删除的节点。
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
    void deleteNode(ListNode* node) {
        ListNode* tmp=node->next;
        //将node后一节点的值复制到node
        node->val=node->next->val;
        //将后一节点删除
        node->next=node->next->next;

        delete tmp;
        //另一个方法，直接修改node指针指向的内容
//        *node=*(node->next);
    }
};