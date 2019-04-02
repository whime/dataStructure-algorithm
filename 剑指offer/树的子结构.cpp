/*输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）*/

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
    int level=1;//level=1表示在比较根节点
    bool flag=false;
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
           bool left,right;
           
           if(pRoot2==NULL&&level==1) return false;//空树不是一个树的子结构
           else if(pRoot2==NULL&&level!=1)
                return true;//比较子节点并达到叶节点
           if(pRoot1==NULL) return false;
           if(pRoot2->val==pRoot1->val)
           {
               level++;
               left=HasSubtree(pRoot1->left,pRoot2->left);
               right=HasSubtree(pRoot1->right,pRoot2->right);
               flag=left&&right;
               if(!flag)
               {
                   //如果父节点相同但不是子结构，则往下和左右节点比较
                    left=HasSubtree(pRoot1->left,pRoot2);
                    right=HasSubtree(pRoot1->right,pRoot2);
                    return left||right;
               }
               return flag;
           }
            else
            {
                if(level==1)
                {
                    //一开始根节点不相等则往下比较
                    left=HasSubtree(pRoot1->left,pRoot2);
                    right=HasSubtree(pRoot1->right,pRoot2);
                    return left||right;
                }
                else return false;//否则就是中途比较时出现了不同，返回false
            }
    }
};

//大牛的做法：先转换成字符串，再查找是不是在其中
#python
class Solution:
    def HasSubtree(self, pRoot1, pRoot2):
         
        def convert(p):
            if p:
                return str(p.val) +  convert(p.left) + convert(p.right)
            else:
                return ""
        return convert(pRoot2) in convert(pRoot1) if pRoot2 else False