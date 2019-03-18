/*��Ŀ����
����ĳ��������ǰ���������������Ľ�������ؽ����ö����������������ǰ���������������Ľ���ж������ظ������֡�
��������ǰ���������{ 1,2,4,7,3,5,6,8 }�������������{ 4,7,2,1,5,3,8,6 }�����ؽ������������ء�*/



/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		TreeNode* root = reConstructBinaryTree(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
		return root;
	}
//��ȫ����ţ�������޴𰸱�д������
private:
	TreeNode* reConstructBinaryTree(vector<int> pre, int preStart, int preEnd, vector<int> vin, int vinStart, int vinEnd)
	{
		TreeNode* root = new TreeNode(pre[preStart]);
		if (preStart>preEnd || vinStart>vinEnd)
		{
			return NULL;
		}
		int i;
		for (i = vinStart; i <= vinEnd; i++)
		{
			if (vin[i] == pre[preStart])
			{
				root->left = reConstructBinaryTree(pre, preStart + 1, preStart + i - vinStart, vin, vinStart, i - 1);
				root->right = reConstructBinaryTree(pre, preStart + i - vinStart + 1, preEnd, vin, i + 1, vinEnd);
				break;
			}
		}
		return root;
	}
};
//python�汾
# -*- coding:utf-8 -*-
# class TreeNode :
	#     def __init__(self, x) :
	#         self.val = x
	#         self.left = None
	#         self.right = None
	class Solution :
	# ���ع����TreeNode���ڵ�
	def reConstructBinaryTree(self, pre, tin) :
	# write code here
	if not pre or not tin:
return None
root = TreeNode(pre.pop(0))
index = tin.index(root.val)
root.left = self.reConstructBinaryTree(pre, tin[:index])
root.right = self.reConstructBinaryTree(pre, tin[index + 1:])
return root

