//感谢https://blog.csdn.net/na_beginning/article/details/62884939
//多重背包问题
//多重背包和01背包、完全背包的区别：多重背包中每个物品的个数都是给定的，可能不是一个，绝对不是无限个。
#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>
//m[i][j]为可选物品为0，1，...，i，背包容量为j的时候的最优值。
//int knapsack(int *w, int *v, int n, int c, int *num,int *used_count)
//{
//	int **m = new int*[n];
//	int totalvalue;
//	for (int i = 0; i < n; i++) 
//	{
//		m[i] = new int[c + 1];
//		m[i][0] = 0;//背包容量为0时总价值为零，什么都没装。
//	}
//	for (int j = 0; j <= c; j++)//只有一种物品
//	{
//		int count = min(num[0], j / w[0]);
//		m[0][j] = count*v[0];//如果count=0,即j<w[0]时，m[0][j]=0也对。
//	}
//
//	for (int i = 1; i < n; i++)
//	{
//		for (int j = 1; j <= c; j++)
//		{
//			if (j < w[i])
//			{
//				m[i][j] = m[i - 1][j];//对第i个物品，容量不够，不取
//			}
//			else
//			{
//				int count = min(num[i], j / w[i]);
//				m[i][j] = m[i - 1][j];//假设不选第i种物品为最优值
//				for (int k = 1; k <= count; k++)//确定选择第i种物品的个数
//				{
//					int tmp = m[i-1][j - k*w[i]]+v[i]*k;
//					m[i][j] = max(m[i][j], tmp);
//				}
//			}
//		}
//	}
//	totalvalue = m[n - 1][c];
//	int i = n - 1;
//	int j = c;
//	while (i)//确定每种物品使用的个数
//	{
//		int count = min(j / w[i], num[i]);
//		for (int k = 1; k <= count; k++)
//		{
//			if (m[i][j] == m[i - 1][j - k*w[i]] + k*v[i])
//			{
//				used_count[i] = k;
//				j -= k*w[i];
//				break;
//			}
//		}
//		i--;
//	}
//	used_count[0] = m[0][j] / v[0];
//	for (int i = 0; i < n; i++)
//	{
//		delete m[i];
//		m[i] = NULL;
//	}
//	delete[]m;
//	m = NULL;
//	return totalvalue;
//}
//int main()
//{
//	int n, c;
//	cout << "输入物品种类和背包容量：";
//	while (cin >> n >> c)
//	{
//		int *W = new int[n];
//		int *V = new int[n];
//		int *num = new int[n];
//		int *used_count = new int[n]();//默认初始化为零
//		int w, v, number, i = 0;
//		while (i < n)
//		{
//			cin >> w >> v >> number;
//			W[i] = w;
//			V[i] = v;
//			num[i] = number;
//			i++;
//		}
//		int value = knapsack(W, V, n, c, num, used_count);
//		cout << "最大价值是" << value<<endl;
//		cout << "各种物品选取的数量为：";
//		for (int i = 0; i < n; i++)
//		{
//			cout << used_count[i]<<" ";
//		}
//		cout << endl;
//		delete used_count; used_count = NULL;
//		delete W; W = NULL;
//		delete V; V = NULL;
//		delete num; num = NULL;
//	}
//}
/*第二种多重背包解法是转化为0-1背包问题求解*/
int knapsack(vector<int> &W, vector<int> &V,vector<int> &tag, int c)
{
	int **m = new int*[W.size()];
	for (int i = 0; i < W.size(); i++)
	{
		m[i] = new int[c+1];//这里需要加1
	}
	for (int i = 0; i < W.size(); i++)//背包容量为0价值为零
	{
		m[i][0] = 0;
	}
	for (int j = 1; j < c + 1; j++)
	{
		m[0][j] = (W[0] < j) ? V[0] : 0;
	}
	for (int i = 1; i < W.size(); i++)
	{
		for (int j = 1; j < c + 1; j++)
		{
			if (W[i] > j)	m[i][j] = m[i - 1][j];
			else
			{
				m[i][j] = max(m[i - 1][j], (m[i - 1][j - W[i]] + V[i]));
			}
		}
	}
	int value = m[W.size() - 1][c];
	int j = c;
	int i = W.size() - 1;
	for (; i >= 1; i--)
	{
		if (m[i][j] == m[i - 1][j - W[i] ]+ V[i])
		{
			tag[i] = 1;
			j -= W[i];
		}
	}
	tag[0] = (W[0] > j) ? 0 : 1;
	for (int i = 0; i < W.size();i++)
	{
		delete m[i];
		m[i]=NULL;
	}
	delete m;
	m = NULL;
	return value;
}
int main()
{
	int N,w,v,c;
	cout << "请输入物品的种类数目和背包容量：" << endl;
	cin >> N >> c;
	int *quatity = new int[N];
	vector<int> W, V;
	cout << "请输入各种物品的重量，价值，数目：" << endl;
	int i = 0,tmp;
	while (N--)
	{
		cin >> w >> v >> quatity[i];
		tmp = quatity[i];
		while (tmp--)
		{
			V.push_back(v);
			W.push_back(w);
		}
		i++;
	}
	vector<int> tag;
	for (int i = 0; i < W.size(); i++)
		tag.push_back(0);
	int value = knapsack(W, V, tag, c);
	cout << "总价值为" << value<<endl;
	int number =quatity[0];
	i = 0;
	int j = 0, count = 0;
	cout << "各种物品取用数目为：" << endl;
	while (i < tag.size())
	{
		if (i < number)
		{
			if (tag[i])	count++;
		}
		else
		{
			cout << count << " ";
			j++;
			number+=quatity[j];
			count = (tag[i]) ? 1 : 0;
		}
		i++;
	}
	cout << count << endl;
	delete quatity;
	quatity = NULL;
}

