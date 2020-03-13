/**
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
问总共有多少条不同的路径？
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        //组合问题，从n-m-2中取出m-1的组合个数
        int dividend,divisor;//被除数，除数
        dividend=m+n-2;divisor=min(m-1,n-1);
        double res=1;
        for(int i=0;i<divisor;i++)
        {
            //防止溢出,每步一除
            res*=((dividend-i)*1.0/(divisor-i));
        }
        return res+0.5;
    }
};

//dp，每个格子的路径数等于上个格子和左边格子的路径数的和
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1||n==1)  return 1;
        vector<int> row(n,1);
        vector<vector<int>> matrix(m,row);

        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                matrix[i][j]=matrix[i][j-1]+matrix[i-1][j];
            }
        }
        return matrix[m-1][n-1];
    }
};