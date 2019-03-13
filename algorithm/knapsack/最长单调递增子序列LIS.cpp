#include <cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
//最长单调递增子序列解法
//一种是利用排序结合最长公共子序列LCS求解，不赘述
//第二种是利用双重循环实现逐个比较得出最长单调子序列的长度，先得出第一个元素
//结尾的序列的最长单调子序列为其本身，第二个元素如果比第一个元素大，则以第二个
//元素结尾的序列的最长单调序列为其两个元素，以此类推。

int len[50];//用于记录以对应索引的元素为结尾的序列的单调递增子序列的长度
int index[50];//用于记录当前递增序列的前一个元素，便于打印输出。
int sequence[50];//用于保存序列
void printseq(int pointer) {
	if (index[pointer] == -1) {
		cout << sequence[pointer]<< " ";
		return;
	}
	printseq(index[pointer]);
	cout << sequence[pointer] << " ";

}
int main()
{
	cout << "输入序列长度：" << endl;
	int n;
	cin >> n;
	cout << "输入序列：" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> sequence[i];
	}
	int length=0,longest_index;//用于记录最长单调子序列的长度和该子序列最后一个元素的下标。
	len[0] = 0;
	for (int i = 0; i < n; i++)
	{
		int tempmax = 0;
		index[i] = -1;
		/*用-1代表以第i个元素为初始递增序列，长度为1，
		即假设第i个元素前面没有元素可加入进来*/
		for (int j = i - 1; j >= 0; j--)
		{
			if (sequence[i] > sequence[j] && tempmax < len[j])
			{
				tempmax = len[j];
				index[i] = j;
			}
		}
		len[i] = tempmax + 1;
		if (len[i] > length)
		{
			length = len[i];
			longest_index = i;
		}
	}
	cout << "最长单调递增子序列的长度为：" << length<<endl;
	printseq(longest_index);
	return 0;
}
