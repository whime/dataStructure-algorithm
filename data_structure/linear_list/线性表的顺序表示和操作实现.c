#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int Status;
typedef int ElemType;
typedef struct {
	ElemType *elem;
	int length;
	int listsize; 
}SqList; 
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define  OK 1
#define  ERROR 0
#define  TRUE 1
#define  FALSE 0
#define  INFEASIBLE -1
#define  OVERFLOW -2
Status Equal(int a,int b)
{
	if(a==b)   return OK;
	else return ERROR;
}//use in LocateElem
Status visit(SqList L)
{
	if(!L.elem)   return ERROR;
	else {
		printf("show the list:\n");
		for(int i=0;i<L.length;i++)
		{
			printf("%d ",L.elem[i]);
		}
		printf("\n");
		return OK;
	}
}//just do some print
Status ListTraverse(SqList L)
{
   	if(L.elem)
   	{
   		visit(L);
	   }
	   else return ERROR;
}
Status InitList(SqList &L)
{
	L.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L.elem)   return ERROR;
	else {
	printf("enter the length of the list:\n");
	scanf("%d",&L.length);
	printf("enter the elems in order\n");
	for(int i=0;i<L.length;i++)
	{
		scanf("%d",&L.elem[i]);
	}
	L.listsize=LIST_INIT_SIZE;
	}
}

Status DestroyList(SqList &L)
{
	if(L.elem)
	{
	 free(L.elem);
   	 L.elem=NULL;
   	 exit(1);
	}
	else return ERROR;
}

Status ListEmpty(SqList L)
{
	if(L.length==0)  printf("List is empty!\n");
	else printf("List is not empty!\n");
}

Status ListLength(SqList L)
{
     printf("the length of the list is:%d\n",L.length);
}

Status GetElem(SqList L,Status pos,Status &e)
{
    if(pos>L.length||pos<1)   
    {
    	printf("ERROR!\n");
    	return ERROR;
	}
	else {
		e=L.elem[pos-1];
		printf("the elem is:%d\n",e);
	}	
	
}

Status LocateElem(SqList L,Status e,Status (*pf)(int,int))
{
	if(!L.elem)  return ERROR;
	if(L.length==0) return 0;
	else{
		int i=0;
		for(;i<L.length;i++)
		{
			if(pf(L.elem[i],e))  break;
		 } 
		 if(i<L.length)   printf("the position of the elem is:%d\n",i+1);
		 else printf("the elem doesnt exit in the list!\n"); 
	}
}

Status PriorElem(SqList L,Status cur_e,Status &pre_e)
{
	int i;
	for(i=0;i<L.length;i++)
	{
		if(L.elem[i]==cur_e)   {
			pre_e=L.elem[i-1];
			break;
		}
	}
    if(i==L.length||i==0)  printf("Error!\n");
	else printf("the prior elem is %d\n",pre_e); 
	return 0;
}

Status NextElem(SqList L,Status cur_e,Status &next_e)
{
	int i;
	for(i=0;i<L.length-1;i++)
	{
		if(L.elem[i]==cur_e){
			next_e=L.elem[i+1];
			break; 
		}
	}
	if(i==L.length-1)   printf("Error!\n");
	else printf("the next elem is %d\n",next_e);
	return 0; 
}

Status ListInsert(SqList &L,Status i,Status e)
{
	ElemType *newbase,*p,*q;
	if(i<1||i>L.length+1)   return ERROR;
	if(L.length>=LIST_INIT_SIZE)  {
		newbase=(ElemType *)realloc(L.elem,(LIST_INIT_SIZE+LISTINCREMENT)*sizeof(ElemType));
		if(!newbase)  exit(OVERFLOW);
		L.elem=newbase;
		L.listsize+=LISTINCREMENT;
	}
	q=&L.elem[i-1];
	for(p=&L.elem[L.length-1];p>=q;p--)
	{
		*(p+1)=*p; 
	}
	*q=e;
	L.length++;
	return OK;
}

Status ListDelete(SqList &L,Status i,Status &e)
{
	ElemType *p,*q;
	if(i<1||i>L.length)   
	{
		printf("ERROR!");
		return ERROR;
	}
	q=&L.elem[i-1];
	e=*q;
	 for(++q,p=&L.elem[L.length-1];q<=p;q++)//there are difference between ++q and q++;
	 {
	 	*(q-1)=*q;
	 }
	 	L.length--;
	 	return OK;
}
int main()//all operation of linear_list 
{
	SqList L;
	int (*pf)(int,int)=Equal;//use a function pointer
	InitList(L);
	printf("choose the operation you want by enter the number(0 for end):\n");
	printf("<--------the opertions available:-------->\n");
	printf("<--------0、delete the list and exit---->\n");
	printf("<--------1、is the list empty?---------->\n");
	printf("<--------2、ask for Listlength.--------->\n");
	printf("<--------3、get elem from list.--------->\n");
	printf("<--------4、locate elem in list--------->\n");
	printf("<--------5、get prior elem.------------->\n");
	printf("<--------6、get next elem.-------------->\n");
	printf("<--------7、make some parentheses------->\n");
	printf("<--------8、make some deletion---------->\n");
	printf("<--------9、traverse the list.---------->\n");
	ElemType selection;
	scanf("%d",&selection);
	while(1)
	{
		switch(selection)
		{
		case 0:{
			DestroyList(L);
			break;
		}
		case 1:
			{
				ListEmpty(L);
				break;
			}
		case 2:
			{
				ListLength(L);
				break;
			}
		case 3:{
				int i,e;
				printf("enter the position of the data you want:\n");
				scanf("%d",&i);
				GetElem(L,i,e);
				break;
			}
		case 4:{
				int e;
				printf("enter the elem you want to find:\n");
				scanf("%d",&e);
				LocateElem(L,e,*pf);
				break;
			}
		case 5:{
			int pre_e,cur_e;
			printf("enter the current elem :\n");
			scanf("%d",&cur_e);
			PriorElem(L,cur_e,pre_e);
			break;
		}
		case 6:{
			int cur_e,next_e;
		    printf("enter the  current elem:\n");
		    scanf("%d",&cur_e);
		    NextElem(L,cur_e,next_e);//dont use '&' in function main!
			break;
		} 
		case 7:{
			int i,e;
			printf("enter the position behind where you want to insert,and the elem to be inserted:\n");
			scanf("%d %d",&i,&e);
			ListInsert(L,i,e);
			break;
		}
		case 8:{
			int i,e;
			printf("enter the position of the elem you want to delete:\n");
			scanf("%d",&i);
			ListDelete(L,i,e);
			break;
		}
		case 9:{
			ListTraverse(L);
			break;
		} 
	}
	scanf("%d",&selection);
  }
 }