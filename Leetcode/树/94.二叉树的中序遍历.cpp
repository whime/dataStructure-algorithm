//给定一个二叉树，返回它的中序遍历。
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* cur=root;
        while(!s.empty()||cur)
        {
            if(cur)
            {
                s.push(cur);
                cur=cur->left;
            }
            else
            {
                cur=s.top();
                s.pop();
                res.push_back(cur->val);
                cur=cur->right;
            }
        }
        return res;
    }

};