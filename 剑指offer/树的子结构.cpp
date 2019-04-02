/*�������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��*/

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
    int level=1;//level=1��ʾ�ڱȽϸ��ڵ�
    bool flag=false;
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
           bool left,right;
           
           if(pRoot2==NULL&&level==1) return false;//��������һ�������ӽṹ
           else if(pRoot2==NULL&&level!=1)
                return true;//�Ƚ��ӽڵ㲢�ﵽҶ�ڵ�
           if(pRoot1==NULL) return false;
           if(pRoot2->val==pRoot1->val)
           {
               level++;
               left=HasSubtree(pRoot1->left,pRoot2->left);
               right=HasSubtree(pRoot1->right,pRoot2->right);
               flag=left&&right;
               if(!flag)
               {
                   //������ڵ���ͬ�������ӽṹ�������º����ҽڵ�Ƚ�
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
                    //һ��ʼ���ڵ㲻��������±Ƚ�
                    left=HasSubtree(pRoot1->left,pRoot2);
                    right=HasSubtree(pRoot1->right,pRoot2);
                    return left||right;
                }
                else return false;//���������;�Ƚ�ʱ�����˲�ͬ������false
            }
    }
};

//��ţ����������ת�����ַ������ٲ����ǲ���������
#python
class Solution:
    def HasSubtree(self, pRoot1, pRoot2):
         
        def convert(p):
            if p:
                return str(p.val) +  convert(p.left) + convert(p.right)
            else:
                return ""
        return convert(pRoot2) in convert(pRoot1) if pRoot2 else False