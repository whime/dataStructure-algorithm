#include<stdio.h>
#include<stdlib.h>
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
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;
Status GetElem_L(LinkList L,int i,ElemType &e)
{
	LNode *p=L->next;
	int j=0;
	while(p&&j<i-1)//从第一个结点开始找，向后移动 i-1 次，找到第i个结点； 
	{
		p=p->next;
		j++;
	}
	if(!p||j>i-1)  return ERROR;
	e=p->data;
	return OK;
}
Status ListInsert_L(LinkList &L,int i,ElemType e)//在带头节点的单链线性表L中第i个位置之前插入元素e; 
{
	LNode *p=L;
	int j=0;
	while(j<i-1&&p)
	{
	   p=p->next;
	   j++;	
	}
	if(!p||j>i-1)   return ERROR;
	LNode* q=(LinkList)malloc(sizeof(LNode));
	q->data=e; q->next=p->next;p->next=q;
	return OK;
}	
Status ListDelete_L(LinkList &L,int i,ElemType &e)//在带头节点的单链线性表L中删除第i个元素，并由e返回其值 
{
	LNode *p=L;
	int j=0;
	while(p&&j<i-1)
	{
		p=p->next;
		j++;
	}
	if(!p||j>i-1)  return ERROR;
	LNode *q=p->next;
	p->next=q->next;
	e=q->data;
	free(q);
	return OK;
}
void CreatList_L(LinkList &L,int n)//逆位序输入n个元素的值，建立带表头结点的单链线性表L 
{
	printf("逆位序输入n个元素的值:");
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	for(int i=n;i>0;i--)
	{
		LNode *p=(LinkList)malloc(sizeof(LNode));
		scanf("%d",&p->data);
		p->next=L->next;L->next=p;
	 } 
 } 
Status ListPrint_L(LinkList L)
{
	LNode *p=L->next;
	while(p)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
int main()
{
	LinkList L;
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