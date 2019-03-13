#include"stdafx.h"
#include<iostream>
//汉诺塔问题
int count = 0;
void move(char x, int n, char z)
{
	printf("%i.move disk %i from %c to %c\n", ++count, n, x, z);
}
void hanoi(int n, char x, char y, char z)
{
	//将塔座x上按直径由小到大且自上而下编号为1到n的n个圆盘按规则搬到塔座z上，y可用作辅助塔座
	if (n == 1)
		move(x, 1, z);
	else {
		hanoi(n - 1, x, z, y);
		move(x, n, z);
		hanoi(n - 1, y, x, z);
	}
}


int main()
{
	hanoi(8, 'X', 'Y', 'Z');
}
