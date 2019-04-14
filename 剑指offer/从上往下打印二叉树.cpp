//从上往下打印出二叉树的每个节点，同层节点从左至右打印。
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        if(root==nullptr) return res;
        vector<TreeNode*> nodes;
        nodes.push_back(root);
        for(vector<TreeNode*>::size_type i=0;i<nodes.size();i++)
        {
            if(nodes[i]!=NULL)
            {
               if(nodes[i]->left!=NULL)    nodes.push_back(nodes[i]->left);
                if(nodes[i]->right!=NULL)    nodes.push_back(nodes[i]->right);
            }
            
        }
       
        for(vector<TreeNode*>::size_type i=0;i<nodes.size();i++)
        {
            res.push_back(nodes[i]->val);
        }
        return res;
    }
};