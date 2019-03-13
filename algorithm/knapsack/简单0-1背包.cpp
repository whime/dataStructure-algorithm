#include <cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

using namespace std;
//0-1背包问题，m[i][j]数组表示可选物品有i,i+1,i+2,...,n，背包容量为j的时候的最优值。
void Knapsack(int *v, int *w, int c, int n, int m[50][50])//复杂度O(nc)
{
	int jMAX = min(w[n] - 1, c);
	for (int j = 0; j <= jMAX; j++)	m[n][j] = 0;//可选物品只有第n个，背包容量不够时价值为0
	for (int j = w[n]; j <= c; j++)	m[n][j] = v[n];//背包容量足够装下第n个物品时价值为v[n]。
	//对剩下的n-1个物品逐个考虑。
	for (int i = n - 1; i > 1; i--)
	{
		jMAX = min(w[i] - 1, c);
		for (int j = 0; j <= jMAX; j++)m[i][j] = m[i + 1][j];//容量不足，不装
		for (int j = w[i]; j < c; j++)	m[i][j] = max(m[i + 1][j], (m[i + 1][j - w[i]] + v[i]));
		//容量够，可以选择装与不装。
	}
	m[1][c] = m[2][c];
	if (c >= w[1])	m[1][c] = max(m[1][c], (m[2][c - w[1]] + v[1]));
}
void Traceback(int m[50][50], int *w, int c, int n, int *x)//复杂度O(n)
{
	//x[]用于记录背包取与不取的bool值。
	for (int i = 1; i < n; i++)
	{
		if (m[i][c] == m[i + 1][c])	x[i] = 0;
		else {
			x[i] = 1;
			c -= w[i];
		}
	}
	x[n] = (m[n][c]) ? 1 : 0;
}

int main()
{
	int n = 5, c = 10;
	int w[6] = { 0,2,2,6,5,4 }, v[6] = {0, 6,3,5,4,6 };//第一个数组元素占位用，无意义
	int m[50][50], x[6];
	Knapsack(v, w, c, n, m);
	Traceback(m, w, c, n, x);
	cout << "选取的价值依次是：" << endl;
	for (int i = 1; i <= n; i++)
	{
		if (x[i])	cout << v[i] << " ";
	}
	cout << endl;
}
