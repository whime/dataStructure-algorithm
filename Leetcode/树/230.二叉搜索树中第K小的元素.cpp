/**
给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。
说明：
你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int count=0,res;
    int kthSmallest(TreeNode* root, int k) {
        inOrder(root,k);
        return res;
    }

    void inOrder(TreeNode* root,int k)
    {
        if(!root||count==k)   return;
        if(root->left)  kthSmallest(root->left,k);
        if(++count==k)  res=root->val;
        if(root->right) kthSmallest(root->right,k);
    }
};