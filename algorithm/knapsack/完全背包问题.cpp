//完全背包问题，与0-1背包的区别是一种物品可以选择多次，不止一个。
#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
/*w表示物品重量，v表示价值，n表示有n种物品，c表示背包容量，
	m[i][j]表示可选物品只有i,i+1,...n，背包容量为j的时候的最优值。*/
int m[50][50];
void knapsack(int *w, int *v, int n, int c)//时间复杂度O(nc)
{
	int jMAX = min(w[n] - 1, c);
	//对第n个物品单独处理
	for (int j = 0; j <= jMAX; j++)	m[n][j] = 0;
	for (int j = w[n]; j <= c; j++)	m[n][j] = (j/w[n])*v[n];//第n个物品可以有多个
	for (int i = n - 1; i > 0; i--)
	{
		jMAX = min(w[i] - 1, c);
		for (int j = 0; j <= jMAX; j++)	m[i][j] = m[i + 1][j];
		for (int j = w[i]; j <= c; j++)	m[i][j] = max(m[i + 1][j], m[i][j - w[i]] + v[i]);
		//与0-1背包的区别就是max函数里面的第二项的m[i][j-w[i]]而不是m[i+1][j-w[i]],即第i个物品取完之后可以再取。
	}
}
void traceback(int *v,int *w,int n,int *x,int c)//时间复杂度O(n)
{
	for(int i = 1; i <= n; i++)
	{
		if (m[i][c] == m[i][c - w[i]]+v[i])
		{
			c -= w[i];
			x[i]++;
		}
		else x[i] = 0;
		}

}
int main()
{
	int n = 5, c = 10;
	int w[6] = { 0,2,2,6,5,4 }, v[6] = { 0,6,3,5,4,6 };
	int x[6] = { 0 };
	knapsack(w, v, n, c);
	traceback(v, w, n, x, c);
	cout << "选取物品的个数依次是：" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << x[i]<<" ";
	}
	cout << endl;
}
