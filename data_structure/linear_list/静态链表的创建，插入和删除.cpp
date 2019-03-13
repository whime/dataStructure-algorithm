/*静态链表实现插入删除*/ 
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1000 
#define INCREMENT 10
#define  OK 1
#define  ERROR 0
#define  TRUE 1
#define  FALSE 0
#define  INFEASIBLE -1
#define  OVERFLOW -2
typedef int Status;
typedef int ElemType;
typedef struct DuLNode{
	ElemType data;
	int cur; 
}component,SLinkList[MAXSIZE];
Status init_SL(SLinkList &space)//将一维数组space中各分量连成一个备用链表，space[0].cur为头指针 
{
	for(int i=0;i<MAXSIZE-1;i++)
	{
		space[i].cur=i+1;
	 } 
	 space[MAXSIZE-1].cur=0;
}
int Malloc_SL(SLinkList &space)//个人理解，此处仅仅只是用space[0].cur存储备用链表头指针，每次调用逐个向下查找而已 
{
	int i=space[0].cur;
	if(space[0].cur)   space[0].cur=space[i].cur;//预先指向下一个没有元素的结点； 
	return i;//返回当前可插入的结点； 
 }
void Free_SL(SLinkList &space,int k)
{
	space[k].cur=space[0].cur; space[0].cur=k;
 } //将下标为 k 的结点插入到备用链表最前面 
Status Creat_SL(SLinkList &space,ElemType &S_head,ElemType &S_tail)
{
	int n;
	init_SL(space);
	S_tail=S_head=Malloc_SL(space);//此时space[0].cur=2 
	printf("输入链表元素个数：\n");
	scanf("%d",&n);
	printf("输入元素：\n");
	while(n--)
	{
	   int i=Malloc_SL(space);
	   scanf("%d",&space[i].data);
	   space[S_tail].cur=i;
	   S_tail=i;	    
	}
	space[S_tail].cur=0;//0 表示空指针 
 } 
Status Delete_SL(SLinkList &space,ElemType &S_head,ElemType &S_tail)
{
	int n,elem,pre,k;
	printf("输入要删除元素的个数：\n");
	scanf("%d",&n);
	printf("输入要删除的元素：\n");
	while(n--)
	{
		pre=S_head;
		k=space[S_head].cur;//以上两行需要在循环里面，即删除一个元素之后重新从头查找 
		scanf("%d",&elem);
	   while(k!=space[S_tail].cur&&space[k].data!=elem)
	   {
	   	   pre=k;
	   	   k=space[k].cur;
	   }
	   if(k==space[S_tail].cur)  {
	   	printf("没有此元素:%d!\n",elem);
	   	return ERROR;
	   } 
	   else {
	   	space[pre].cur=space[k].cur;
	   	Free_SL(space,k);
	   	if(k==S_tail)  pre=S_tail;
	   }
	}
 } 
Status Insert_SL(SLinkList &space,ElemType &S_tail)
{
	int n,i;
	printf("输入插入元素的个数：\n");
	scanf("%d",&n); 
    i=Malloc_SL(space);
    printf("输入插入的元素：\n");
    while(n--) 
    {
	scanf("%d",&space[i].data);
	space[i].cur=space[S_tail].cur;
	space[S_tail].cur=i;
	S_tail=i; 
	i=Malloc_SL(space);
	}
		
}
Status Print_SL(SLinkList space,ElemType S_head)
{
	int i=space[S_head].cur; 
	while(i!=0)
	{
		printf("%d ",space[i].data);
		i=space[i].cur; 
	}
	printf("\n");
}
int main()
{
	ElemType choice,S_head,S_tail;//S_head，S_tail为静态链表头尾结点 
	SLinkList SL;
	printf("operations:1、creat\n");
	printf("           2、delete\n");
	printf("           3、insert\n");
	printf("           4、print\n");
	printf("选择操作：\n");
	while(scanf("%d",&choice))
	{
		switch(choice)
		{
			case 1:{
				Creat_SL(SL,S_head,S_tail);
				break;
			}
			case 2:{
				Delete_SL(SL,S_head,S_tail);
				break;
			}
			case 3:{
			    Insert_SL(SL,S_tail);
				break;
			} 
			case 4:{
				Print_SL(SL,S_head);
				break;
			}
			default:exit(0);
		}
	}
}
