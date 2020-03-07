/**
在农场中，奶牛家族是一个非常庞大的家族，对于家族中的母牛，从它出生那年算起，第三年便能成熟，
成熟的母牛每年可以生出一只小母牛。即母牛从出生开始的第三年便能做妈妈。最开始农场只有一只母牛，
它从第二年开始生小母牛。请设计一个高效算法，返回第n年的母牛总数，已知n的范围为int范围内的正整数。
给定一个正整数n，请返回第n年的母牛总数，为了防止溢出，请将结果Mod 1000000007。
*/
class Cows {
public:
    int countSum(int n) {
        // write code here
    if(n<1) return 0;
    if(n<=3)     return n;
    vector<vector<long long>> baseMatrix={{1,1,0},{0,0,1},{1,0,0}};
    vector<vector<long long>> res=matrixPower(baseMatrix,n-3);
    return (res[0][0]*3+res[1][0]*2+res[2][0])%1000000007;

    //由于有大数，使用O(n)的时间复杂度无法通过
    //使用矩阵的快速幂乘，复杂度O(lgn),参考https://www.nowcoder.com/questionTerminal/f26698ae586b46428c87a5dbcdae272c
    }
    vector<vector<long long>> multiMatrix(vector<vector<long long>> A,vector<vector<long long>> B)
    {
        vector<vector<long long>> result(A.size(),vector<long long>(B[0].size()));
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<B[0].size();j++)
            {
                for(int k=0;k<B.size();k++)
                {
                    result[i][j]+=(A[i][k]*B[k][j])%1000000007;
                    result[i][j]%=1000000007;
                }
            }
        }
        return result;
    }

    //矩阵快速幂
    vector<vector<long long>> matrixPower(vector<vector<long long>> base,int time)
    {
        vector<vector<long long>> res(base.size(),vector<long long>(base[0].size()));
        for(int i=0;i<base.size();i++)
        {
            res[i][i]=1;
        }
        vector<vector<long long>> tmp=base;
        while(time)
        {
            if(time&1)
            {
                res=multiMatrix(res,tmp);
            }
            tmp=multiMatrix(tmp,tmp);
            time>>=1;
        }
        return res;

    }
};