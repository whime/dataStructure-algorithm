//快速排序找出第K个最小的元素  

/*借助快速排序的思想，在n个元素的序列中，求出第k个最小的元素*/ 
#include<stdio.h>
#include<stdlib.h>//system函数需要用到 
typedef int Status;
Status partion(Status* a,Status low,Status high)
{
	int pivotkey=a[low];
	while(low<high)
	{
		while(low<high&&a[high]>pivotkey)
		high--;
		a[low]=a[high];
		while(low<high&&a[low]<pivotkey)
		low++;
		a[high]=a[low];
	}
	a[low]=pivotkey;//一开始忘记了将pivotkey赋值给a[low] 
	return low;
 } 
Status searchKmin(Status *a,Status low,Status high,Status k)
{
	if(low<=high)
	{
		Status pivotloc=partion(a,low,high);
		if(pivotloc==(k-1))    return a[pivotloc];
		else if(pivotloc<(k-1))   searchKmin(a,pivotloc+1,high,k);
		else  searchKmin(a,low,pivotloc-1,k);
	}
	else return -1;
}

int main()
{
	int a[20]={25,59,98,63,54,89,30,12,45,78,100};
	int k;
	printf("输入查找的K值：\n");
		scanf("%d",&k);//输入K之后才会执行system语句，窗口变色； 
	int mink=searchKmin(a,0,10,k);
	printf("第%d小的元素是：%d",k,mink); 
	system("color 2A");//查资料看到，纯粹玩玩
}
