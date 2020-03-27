/**
在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，
聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。
计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。
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