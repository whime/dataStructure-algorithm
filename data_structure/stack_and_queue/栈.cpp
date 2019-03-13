#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
using namespace std;
typedef int STACKELEMTYPE;

//简单堆栈使用


typedef struct {
	STACKELEMTYPE *base;
	STACKELEMTYPE *top;
	int stacksize;
}STACK;
bool initStack(STACK &S)
{
	S.base = (STACKELEMTYPE *)malloc(STACK_INIT_SIZE * sizeof(STACKELEMTYPE));
	if (!S.base) return false;
	S.top = S.base;				//空栈
	S.stacksize = STACK_INIT_SIZE;
	return true;
}//初始化空栈
bool getTop(STACK S, STACKELEMTYPE &e)
{
	//若栈不空，则用e返回S的栈顶元素，并返回true，否则返回false;
	if (S.top == S.base)  return false;
	e = *(S.top--);
	return true;
}
bool push(STACK &S, STACKELEMTYPE e)
{
	//插入元素e为新的栈顶元素
	if (S.top - S.base == S.stacksize)
	{
		S.base = (STACKELEMTYPE*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(STACKELEMTYPE));
		if (!S.base) return false;
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;//++运算符优先级比*高
	return true;
}
bool pop(STACK &S, STACKELEMTYPE &e)
{
	if (S.top == S.base) return false;
	e = *--S.top;
	return true;
}
 void clearStack(STACK &S)
{
	S.top = S.base;
}
 void destroyStack(STACK &S)
 {
	 free(S.base);
 }
 bool isEmpty(STACK &S)
 {
	 if (S.top == S.base)  return true;
	 else return false;
 }
 int StackLength(STACK &S)
 {
	 return S.stacksize;
 }
 void showMenu()
 {
	 cout << "enter your choice:\n";
	 cout << "\t\t1.isempty" << endl;
	 cout << "\t\t2.push" << endl;
	 cout << "\t\t3.clear" << endl;
	 cout << "\t\t4.pop" << endl;
	 cout << "\t\t5.destroy" << endl;
	 cout << "\t\t6.getTop" << endl;
	 cout << "\t\t7.quit" << endl;
 }
 int main()
 {
	 STACK stack;
	 int choice;
	 STACKELEMTYPE elem;
	 initStack(stack);
	 showMenu();
	 while (cin >> choice)
	 {
		 switch (choice)
		 {
		 case 1:
			 if (isEmpty(stack))   cout << "the stack is empty!" << endl;
			 else cout << "the stack is not empty!" << endl;
			 break;
		 case 2:
			 cout << "enter the element you want to push:" << endl;
			 cin >> elem;
			 if (push(stack, elem))    cout << "push success!";
			 else cout << "push failure!";
			 break;
		 case 3:
			 clearStack(stack);
			 break;
		 case 4:
			 if (pop(stack, elem)) cout << elem << " is pop!";
			 else cout << "stack is empty!";
			 break;
		 case 5:
			 destroyStack(stack);
			 break;
		 case 6:
			 if (getTop(stack, elem))    cout << "the top element is " << elem;
			 else cout << "the stack is empty";
			 break;
		 case 7:
			 return 0;
		 }
		 showMenu();
	 }	 
 }
 