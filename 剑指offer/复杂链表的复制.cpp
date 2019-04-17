/*
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
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


//大牛的算法
class Solution {
public:
    /*
        1、复制每个节点，如：复制节点A得到A1，将A1插入节点A后面
        2、遍历链表，A1->random = A->random->next;
        3、将链表拆分成原链表和复制后的链表
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
        //拆分
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

//我的算法，只考虑到链表的各个节点值不一样，如果一样肯定过不了。
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

	//复制主链
        while(curNode->next)
        {
            RandomListNode* node=new RandomListNode(curNode->next->label);
            
            copyNode->next=node;
            curNode=curNode->next;
            copyNode=copyNode->next;
        }
        curNode=pHead;
        copyNode=copyHead;
        RandomListNode* tmp;//用于查找对应的random节点
	//处理random节点，每次都需要遍历主链
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