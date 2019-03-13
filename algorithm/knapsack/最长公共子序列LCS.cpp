#include <cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
//最长公共子序列LCS
void LCSlength(int m, int n, char *x, char *y, int **c, int **b)
{
	// 时间复杂度为O(m*n)
	int i, j;
	for (i = 0; i <= m; i++)	{
		c[i] = new int[n];
		b[i] = new int[n];
		c[i][0] = 0;
	}
	for (j = 0; j <= n; j++)	c[0][j] = 0;//c二位数组的第一列和第一行都为零
	for(i=1;i<=m;i++)
		for (j = 1; j <= n; j++)
		{
			//这里尤其要注意下标的取值，避免发生内存访问错误
			if (x[i-1] == y[j-1]) { c[i][j] = c[i - 1][j - 1] + 1;	b[i][j] = 1; }
			else if (c[i - 1][j] >= c[i][j - 1]) { c[i][j] = c[i - 1][j]; b[i][j] = 2; }
			else { c[i][j] = c[i][j - 1]; b[i][j] = 3; }
		}
}
//void LCS(int i, int j, char *x, int **b)//打印最长公共子序列
//{
//	//时间复杂度为O(m+n)
//	if (i == 0 || j == 0) return;
//	if (b[i][j] == 1) { LCS(i - 1, j - 1, x, b); cout << x[i-1]; }
//	else if (b[i][j] ==2) { LCS(i - 1, j, x, b); }
//	else { LCS(i, j - 1, x, b); }
//}
/*可以做小小的优化，对于数组元素c[i][j],可以通过比较与c[i-1][j],c[i][j-1]的关系
决定下一步的动作，即可以省略数组b。*/
//LCSlength只要将b数组有关部分去掉即可
//LCS函数可以改为
void LCS(int i, int j, char *x, int **c)//打印最长公共子序列
{
	//时间复杂度为O(m+n)
	if (i == 0 || j == 0) return;
	if (c[i][j] == (c[i - 1][j - 1] + 1)) { LCS(i - 1, j - 1, x, c); cout << x[i - 1]; }
	else if (c[i][j] == c[i - 1][j]) { LCS(i - 1, j, x, c); }
	else { LCS(i, j - 1, x, c); }
}
int main()
{
	char x[] = "hello";
	char y[] = "heclo";
	int m = sizeof(x)-1;
	int n = sizeof(y)-1;
	int **b = new int*[m];//优化后数组b可以去掉
	int **c = new int*[m];
	LCSlength(m, n, x, y, c, b);
	LCS(m, n, x, c);
}
