//层序创建、遍历二叉树  
struct biTree * createBiTree(struct biTree * bt){  
    int front,rear;  
    char ch;  
    struct biTree * p,* Queue[MAX];  
    front=1,rear=0;  
    printf("按层输入二叉树，虚结点输入'#'(结束符为'@')：\n");  
    while((ch=getchar())!='@'){  
        p=NULL;  
        if(ch!='#'){  
            p=(struct biTree *)malloc(sizeof(struct biTree));  
            p->data=ch;  
            p->lchild=p->rchild=NULL;  
        }  
        rear++;  
        Queue[rear]=p;  
        if(rear==1){  
            bt=p;  
        }  
        else{  
            if(p!=NULL&&Queue[front]!=NULL){  
                if(rear%2==0){  
                    Queue[front]->lchild=p;  
                }  
                else{  
                    Queue[front]->rchild=p;  
                }  
            }  
            if(rear%2==1){  
                front++;  
            }  
        }  
    }  
    return bt;  
}  
int levelOrderTraverse(struct biTree * bt){  
    struct biTree * Queue[MAX],* p;  
    int front,rear;  
    front=rear=0;  
    if(bt!=NULL){  
        Queue[rear]=bt;  
        rear++;  
        while(front!=rear)  
        {  
            p=Queue[front];  
            front++;  
            printf("%c ",p->data);  
            if(p->lchild!=NULL){  
                Queue[rear]=p->lchild;  
                rear++;  
            }  
            if(p->rchild!=NULL){  
                Queue[rear]=p->rchild;  
                rear++;  
            }  
        }  
    }  
    return 0;  
}  