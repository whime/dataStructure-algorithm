#include"stdafx.h"
#include<iostream>
using namespace std;
#define ElemType int 
#define Status int
#define OK 1
#define ERROR 0
typedef struct QNode{
	ElemType data;
	struct QNode *next;
}QNode, *QueuePtr;
typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;
//链式队列出队入队，销毁
Status initQueue(LinkQueue &Q)
{
	Q.rear = Q.front = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front) exit(EXIT_FAILURE);
	Q.front->next = NULL;
	return OK;
}
Status EnQueue(LinkQueue &Q, ElemType& e)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)	return ERROR;
	p -> data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}
Status DeQueue(LinkQueue &Q, ElemType& e)
{
	//若队列不空，删除队列队头元素，并用e返回其值，并返回OK;否则返回error;
	if (Q.front == Q.rear)	return ERROR;
	QueuePtr p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (p == Q.rear)	Q.rear = Q.front;
	free(p);
	return OK;
}
Status DestroyQueue(LinkQueue &Q)
{
	//销毁队列
	while (Q.front)
	{
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return OK;
}
void showMenu()
{
	cout << "1.enqueue" << endl;
	cout << "2.dequeue" << endl;
	cout << "3.destroyQueue and quit" << endl;
	cout << "enter your choice:" << endl;
}
int main()
{
	LinkQueue q;
	int choice;
	Status elem;
	initQueue(q);
	showMenu();
	while (cin >> choice)
	{
		switch (choice)
		{
		case 1:
			cout << "enter your element to enqueue:" << endl;
			cin >> elem;
			if (EnQueue(q, elem)) cout << "enqueue success!"<<endl;
			else {
				cout << "enqueue failed!" << endl;
				system("pause");
				return ERROR;
			}	
			break;
		case 2:
			if (DeQueue(q, elem))	cout << "dequeue success!";
			else {
				cout << "dequeue failed!" << endl;
				system("pause");
				return ERROR;
			}
			cout << "the element deleted is " << elem<<endl;
			break;
		case 3:
			DestroyQueue(q);
			cout << "bye";
			return OK;
		}
		showMenu();
	}
}
