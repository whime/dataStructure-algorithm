输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的结点，只能调整树中结点指针的指向。


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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode* pre=nullptr;
        if(!pRootOfTree) return nullptr;
        subConvert(pRootOfTree,pre);
        
        TreeNode* res=pRootOfTree;
        //返回最小的不为零的节点
        while(res->left)
        {
            res=res->left;
        }
        return res;
    }
    void subConvert(TreeNode* cur,TreeNode*& pre)
    {
        if(cur==nullptr) return;
        subConvert(cur->left,pre);
        cur->left=pre;
        if(pre!=nullptr) pre->right=cur;
        pre=cur;
        
        subConvert(cur->right,pre);
    }
};