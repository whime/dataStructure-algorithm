����һ�ö��������������ö���������ת����һ�������˫������
Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��


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
        //������С�Ĳ�Ϊ��Ľڵ�
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