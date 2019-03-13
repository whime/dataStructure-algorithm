#include"stdafx.h"
#define MAXQSIZE 100
typedef int QElemType;
typedef struct {
	QElemType *base;
	int front;
	int rear;
}SqQueue;
bool initQueue(SqQueue &Q)
{
	Q.base = (QElemType*)malloc(MAXQSIZE * sizeof(QElemType));
	if (!Q.base) exit(false);
	Q.front = Q.rear = 0;
	return true;
}
int QueueLength(SqQueue Q)
{	//返回队列长度
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}
bool EnQueue(SqQueue &Q, QElemType e)
{
	//插入元素e为Q的新的队尾元素
	if ((Q.rear + 1) % MAXQSIZE == Q.front) return false;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return true;
}
bool DeQueue(SqQueue &Q, QElemType &e)
{
	//若队列不空，则删除Q的队头元素，用e返回其值，返回true;否则返回false;
	if (Q.rear == Q.front) return false;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
}
void DeleteQueue(SqQueue &Q)
{
	free(Q.base);
}
void showMenu()
{
	cout << "1.queue length" << endl;
	cout << "2.enqueue" << endl;
	cout << "3.dequeue" << endl;
	cout << "4.delete queue" << endl;
	cout << "enter your choice:";
}
int main()
{
	int choice;
	QElemType e;
	SqQueue Q;
	initQueue(Q);
	showMenu();

	while (cin >> choice)
	{
		switch (choice)
		{
		case 1:
			cout << "the length of the queue is " << QueueLength(Q) << endl;
			break;
		case 2:
			cout << "enter the element you want to enqueue:";
			cin >> e;
			if (EnQueue(Q, e))	cout << "enqueue success" << endl;
			else exit(EXIT_FAILURE);
			break;
		case 3:
			if (DeQueue(Q, e))  cout << e << " deleted!"<<endl;
			else
			{
				cout << "the queue is empty!" << endl;
				exit(EXIT_FAILURE);
			}
			break;
		case 4:
			DeleteQueue(Q);
			return 0;
			break;
		default: 
			cout << "enter error!";
		}
		showMenu();
	}
}
