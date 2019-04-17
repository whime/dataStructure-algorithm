/*
����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬��һ������ָ��ָ������һ���ڵ㣩�����ؽ��Ϊ���ƺ��������head����ע�⣬���������벻Ҫ���ز����еĽڵ����ã�������������ֱ�ӷ��ؿգ�
*/
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/


//��ţ���㷨
class Solution {
public:
    /*
        1������ÿ���ڵ㣬�磺���ƽڵ�A�õ�A1����A1����ڵ�A����
        2����������A1->random = A->random->next;
        3���������ֳ�ԭ����͸��ƺ������
    */
     
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead) return NULL;
        RandomListNode *currNode = pHead;
        while(currNode){
            RandomListNode *node = new RandomListNode(currNode->label);
            node->next = currNode->next;
            currNode->next = node;
            currNode = node->next;
        }
        currNode = pHead;
        while(currNode){
            RandomListNode *node = currNode->next;
            if(currNode->random){               
                node->random = currNode->random->next;
            }
            currNode = node->next;
        }
        //���
        RandomListNode *pCloneHead = pHead->next;
        RandomListNode *tmp;
        currNode = pHead;
        while(currNode->next){
            tmp = currNode->next;
            currNode->next =tmp->next;
            currNode = tmp;
        }
        return pCloneHead;
    }
};

//�ҵ��㷨��ֻ���ǵ�����ĸ����ڵ�ֵ��һ�������һ���϶������ˡ�
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead) return NULL;
        RandomListNode *node,*curNode,*copyNode;
        RandomListNode *copyHead=new RandomListNode(pHead->label);
        curNode=pHead;
        copyNode=copyHead;

	//��������
        while(curNode->next)
        {
            RandomListNode* node=new RandomListNode(curNode->next->label);
            
            copyNode->next=node;
            curNode=curNode->next;
            copyNode=copyNode->next;
        }
        curNode=pHead;
        copyNode=copyHead;
        RandomListNode* tmp;//���ڲ��Ҷ�Ӧ��random�ڵ�
	//����random�ڵ㣬ÿ�ζ���Ҫ��������
        while(curNode)
        {
            if(curNode->random)
            {
                
                for(tmp=copyHead;tmp;tmp=tmp->next)
                {
                    if(tmp->label==curNode->random->label)
                    {
                        break;
                    }
                }
                copyNode->random=tmp;
                
            }
            curNode=curNode->next;
            copyNode=copyNode->next;
        }
        return copyHead;
    }
};