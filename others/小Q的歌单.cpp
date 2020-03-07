/**
小Q有X首长度为A的不同的歌和Y首长度为B的不同的歌，现在小Q想用这些歌组成一个总长度正好为K的歌单，
每首歌最多只能在歌单中出现一次，在不考虑歌单内歌曲的先后顺序的情况下，请问有多少种组成歌单的方法。
input:
每个输入包含一个测试用例。
每个测试用例的第一行包含一个整数，表示歌单的总长度K(1<=K<=1000)。
接下来的一行包含四个正整数，分别表示歌的第一种长度A(A<=10)和数量X(X<=100)以及歌的第二种长度B(B<=10)和数量Y(Y<=100)。保证A不等于B。
output:
输出一个整数,表示组成歌单的方法取模。因为答案可能会很大,输出对1000000007取模的结果。
*/
#include<iostream>
using namespace std;
//根据组合问题的性质，C(n,k) = C(n-1,k) + C(n-1,k-1）构造杨辉三角
//C[n][k]表示C(n,k),从n个中取出k个的组合数
void YHtriangle(long long c[][101])
{
    c[0][0]=1;
    //获取数组长度不能使用sizeof(c),c只是一个long long型的指针，大小为8
    //将数组传参给指针，获取数组长度可以通过指定各个维度的大小实现
    for(int i=1;i<=100;i++)
    {
        c[i][0]=1;
        for(int j=1;j<=i;j++)
        {
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%1000000007;
        }
    }

}
int main()
{
    int x,y,a,b,k;
    long long c[101][101]{0};//初始化为0，避免读脏数据
    YHtriangle(c);
    long long res;
    while(cin>>k>>a>>x>>b>>y)
    {
        res=0;
        if(a!=b)
        {
        //逐个查找符合条件的a和b的个数
            for(int i=0;i<=x;i++)
            {
                for(int j=0;j<=y;j++)
                {
                    if((i*a+j*b)>k)    break;
                    if((i*a+j*b)==k)
                        res+=c[x][i]*c[y][j];
                }
            }
            cout<<res%1000000007;
        }
    }

}

/**
//0-1背包
#include<iostream>
using namespace std;
int main()
{
    int dp[201][1001];
    int c[201];
    dp[0][0]=1;
    int k,a,x,b,y;
    while(cin>>k>>a>>x>>b>>y)
    {
        for(int i=1;i<=x;i++)
        {
            c[i]=a;
        }
        for(int j=x+1;j<=x+y;j++)
        {
            c[j]=b;
        }
        for(int i=1;i<=x+y;i++)
        {
            for(int j=0;j<=k;j++)
            {
                if(j>=c[i])
                {
                    dp[i][j]=(dp[i-1][j]+dp[i-1][j-c[i]])%1000000007;
                }
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        cout<<dp[x+y][k];
    }
}
*/

