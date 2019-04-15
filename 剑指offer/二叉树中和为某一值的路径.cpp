/*
输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路
径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。(注意: 
在返回值的list中，数组长度大的数组靠前)
*/
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

//都是抄的
class Solution {
    vector<vector<int>> result;
    vector<int> tmp;
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root==NULL) return result;
        tmp.push_back(root->val);
        expectNumber-=root->val;
        if(expectNumber==0&&!root->left&&!root->right)
        {
            result.push_back(tmp);
        }
        else
        {
            FindPath(root->left,expectNumber);
            FindPath(root->right,expectNumber);
        }
        tmp.pop_back();
        return result;
    }
    
};