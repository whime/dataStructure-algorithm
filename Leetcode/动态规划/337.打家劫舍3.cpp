/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//递归，内存占用还是比较大
class Solution {
public:
    unordered_map<TreeNode*,int> res;//使用map避免重复计算
    int rob(TreeNode* root) {
        if(!root)   return 0;
        if(res.count(root)) return res[root];

        int left=0,right=0;
        if(root->left)  left=rob(root->left->left)+rob(root->left->right);//当前节点root的左节点的左右子树的最大金额
        if(root->right) right=rob(root->right->left)+rob(root->right->right);
        int sum=max(root->val+left+right,rob(root->left)+rob(root->right));//取根节点和左右子节点以下的最大金额，不取根节点考虑其两个子节点的最大金额
        res.insert(pair<TreeNode*,int>(root,sum));
        return sum;
    }
};

//后序遍历，自底向上
class Solution {
public:
    int rob(TreeNode* root) {
        if(!root)   return 0;
        postOrder(root);
        return root->val;
    }

    void postOrder(TreeNode* root)
    {
        if(root->left)  postOrder(root->left);
        if(root->right) postOrder(root->right);

        int res1=root->val,res2=0;
        if(root->left)
        {
            res2+=root->left->val;
            if(root->left->left)    res1+=root->left->left->val;
            if(root->left->right)    res1+=root->left->right->val;
        }
        if(root->right)
        {
            res2+=root->right->val;
            if(root->right->left)   res1+=root->right->left->val;
            if(root->right->right)  res1+=root->right->right->val;
        }
        root->val=max(res1,res2);
    }
};