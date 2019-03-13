#include<iostream>                                                      
using namespace std;
const int lmax=300;
int main()
{
	int a[lmax+1],b[lmax+1];
	int n,i,j,k;
	while(cin>>n&&n)
	{
		for(i=0;i<=n;i++)
		{
			a[i]=1;b[i]=0;
		}
		for(i=2;i<=17;i++)
		{
			for(j=0;j<=n;j++)
				for(k=0;k+j<=n;k+=i*i)
				{
					b[j+k]+=a[j];
				}
				for(j=0;j<=n;j++)
				{
					a[j]=b[j];
					b[j]=0;
				}
		}
		cout<<a[n]<<endl;
	}
	return 0;
}
另：
#include <iostream>
using namespace std;
const int _max = 10001; 
long long c1[_max], c2[_max];   
int main()
{	
	int nNum;    
	int i, j, k;
 
	while(cin >> nNum)
	{
		for(i=0; i<=nNum; ++i)   // ---- ①首先对c1初始化，由第一个表达式(1+x+x^2+..x^n)初始化，把质量                                          
		{                                                  从0到n的所有砝码都初始化为1.
			c1[i] = 1;
			c2[i] = 0;
		}
		for(i=2; i<=nNum; ++i)   // ----- ②i从2到n遍历，这里i就是指第i个表达式，上面给出的第二种母函数
             {                                                     关系式里，每一个括号括起来的就是一个表达式。
 
			for(j=0; j<=nNum; ++j)   // ----- ③j 从0到n遍历，这里j就是(前面i個表达式累乘的表达式)里第j    
                                                                         个变量。如(1+x)(1+x^2)(1+x^3)，j先指示的是1和x的系数，
                                                                         i=2执行完之后变为（1+x+x^2+x^3）(1+x^3)，这时候j应该指
                                                                         示的是合并后的第一个括号的四个变量的系数。
                 for(k=0; k+j<=nNum; k+=i)  // ---- ④k表示的是第j个指数，所以k每次增i（因为第i个表达式的增量  
                    {                                                     是i）。
		        c2[j+k] += c1[j];
				}
			for(j=0; j<=nNum; ++j)     // -- ⑤把c2的值赋给c1,而把c2初始化为0，因为c2每次是从一个表达                   
			{                                                 式中开始的。
				c1[j] = c2[j];
				c2[j] = 0;
			}
		}
		cout << c1[nNum] << endl;
	}
	return 0;
}
