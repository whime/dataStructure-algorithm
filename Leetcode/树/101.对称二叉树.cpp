//给定一个二叉树，检查它是否是镜像对称的。
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //递归，判断左右子树是否对称=>左节点的值是否等于右节点的值，左节点的左子树与右节点的右子树对称，右节点的左子树与左节点的右子树对称
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)   return true;
        return helper(root->left,root->right);
    }
    bool helper(TreeNode* left,TreeNode* right)
    {
        if(!left&&!right)   return true;
        if(!left||!right)   return false;
        if(left->val==right->val)
        {
            return helper(left->left,right->right)&&helper(left->right,right->left);
        }
        return false;
    }
};
//类似于BFS,将两个要比较的节点放在一起，然后一个从左到右一个从右到左push进子节点，如果整棵树对称那么相邻的两个节点都是相同的
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        stack<TreeNode*> s;
        s.push(root);
        s.push(root);
        TreeNode* left,*right;
        while(!s.empty())
        {
            left=s.top();s.pop();
            right=s.top();s.pop();
            if(!left&&!right)   continue;
            if(!left||!right)   return false;
            if(left->val!=right->val)   return false;
            s.push(left->left);
            s.push(right->right);
            s.push(left->right);
            s.push(right->left);
        }
        return true;
    }
};

