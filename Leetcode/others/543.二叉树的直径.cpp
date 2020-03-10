/**
给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过根结点。
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
    int res=0;
    int diameterOfBinaryTree(TreeNode* root) {
        findLongestLength(root);
        return res;
    }
    int findLongestLength(TreeNode* root)
    {
        if(!root)   return 0;
        int maxlength=1,leftLength=0,rightLength=0;
        if(root->left)  leftLength=findLongestLength(root->left);
        if(root->right) rightLength=findLongestLength(root->right);
        if(res<leftLength+rightLength)    res=leftLength+rightLength;
        maxlength+=std::max(leftLength,rightLength);
        return maxlength;
    }
};