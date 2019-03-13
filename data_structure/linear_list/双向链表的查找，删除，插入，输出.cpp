#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100
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
	struct DuLNode *prior;
	struct DuLNode *next;
}DuLNode,*DuLinkList;
Status GetElem_L(DuLinkList L,int i,ElemType &e)
{
	DuLNode *p=L->next;
	int j=0;
	while(p&&j<i-1)//从第一个结点开始找，向后移动 i-1 次，找到第i个结点； 
	{
		p=p->next;
		j++;
	}
	if(!p||j>i)  return ERROR;
	e=p->data;
	return OK;
}
Status ListInsert_L(DuLinkList &L,int i,ElemType e)//在带头节点的单链线性表L中第i个位置之前插入元素e; 
{
	DuLNode *p=L;
	int j=1;
	while(j<i&&p)
	{
	   p=p->next;
	   j++;	
	}
	if(!p||j>i)    return ERROR;
	DuLNode* q=(DuLinkList)malloc(sizeof(DuLNode));
	q->data=e; 
	q->next=p->next;
	if(p->next)  p->next->prior=q;//p->next不为空 
	p->next=q;q->prior=p;
	return OK;
}	
Status ListDelete_L(DuLinkList &L,int i,ElemType &e)//在带头节点的双向链表L中删除第i个元素，并由e返回其值 
{
	DuLNode *p=L;
	int j=1;
	while(p&&j<i)
	{
		p=p->next;
		j++;
	}//p指向i-1个元素 
	if(!p||j>i)  return ERROR;
	DuLNode *q=p->next;
	if(q->next)   q->next->prior=p;
	p->next=q->next;
	e=q->data;
	free(q);
	return OK;
}
void CreatList_L(DuLinkList &L,int n)//逆位序输入n个元素的值，建立带表头结点的双向链表L 
{
	printf("逆位序输入n个元素的值:");
	L=(DuLinkList)malloc(sizeof(DuLNode));
	L->prior=NULL;
	L->next=NULL;
	for(int i=n;i>0;i--)
	{
		DuLNode *p=(DuLinkList)malloc(sizeof(DuLNode));
		scanf("%d",&p->data);
		p->next=L->next;
		if(p->next) p->next->prior=p;//一开始p->next是NULL,没有这句话会报错 
		L->next=p;p->prior=L;
	 } 
 } 
Status ListPrint_L(DuLinkList L)
{
	DuLNode *p=L->next;
	while(p)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
int main()
{
	DuLinkList L;
	int n,choice,poi;
	ElemType e;
	printf("enter the length of the list:\n");
	scanf("%d",&n);
	CreatList_L(L,n);
	printf("operations:1、insert\n");
	printf("           2、delete\n");
	printf("           3、search\n");
	printf("           4、print\n");
	while(scanf("%d",&choice))
	{
		switch(choice)
		{
			case 1:{
				printf("输入插入元素的位置和值：\n");
				scanf("%d %d",&poi,&e);
				ListInsert_L(L,poi,e);
				break;
			}
			case 2:{
				printf("输入删除元素的位置：\n");
				scanf("%d",&poi);
				ListDelete_L(L,poi,e);
				printf("删除的元素为%d\n",e);
				break;
			}
			case 3:{
				printf("输入所要查找的结点的位置：\n");
				scanf("%d",&poi);
				GetElem_L(L,poi,e);
				printf("第%d个位置为%d\n",poi,e);
				break;
			} 
			case 4:{
				ListPrint_L(L);
				break;
			}
			default:exit(0);
		}
	}
}
