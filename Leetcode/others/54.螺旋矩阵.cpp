/**
给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]
*/
//模拟遍历过程
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty()) return res;//注意判断矩阵是否为空
        int flag=0;//0，1，2，3表示向右，下，左，上遍历矩阵
        int i=0,j=-1;
        int m=matrix.size(),n=matrix[0].size();
        int times=0;//表示每一行或每一列取的数目
        while(m!=0&&n!=0)
        {
            if(flag==0)//向右遍历矩阵的第i列，步数为times
            {
                for(;times<n;times++)
                {
                    j++;
                    res.push_back(matrix[i][j]);
                }
                times=0;
                m--;//行遍历完之后遍历列,由于指针i，j所指的元素已经遍历，所以接下来的列遍历数目少一个
                flag=1;
            }
            else if(flag==1)
            {
                for(;times<m;times++)
                {
                    i++;
                    res.push_back(matrix[i][j]);
                }
                times=0;
                n--;
                flag=2;
            }
            else if(flag==2)
            {
                for(;times<n;times++)
                {
                    j--;
                    res.push_back(matrix[i][j]);
                }
                times=0;
                m--;
                flag=3;
            }
            else
            {
                for(;times<m;times++)
                {
                    i--;
                    res.push_back(matrix[i][j]);
                }
                times=0;
                flag=0;
                n--;
            }
        }
        return res;
    }
};

//更精简，思想基本一样
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return {};
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();
        // 确定上下左右四条边的位置
        int up = 0, down = m - 1, left = 0, right = n - 1;
        while (true)
        {
            for (int i = left; i <= right; i++) res.push_back(matrix[up][i]);
            if (++up > down) break;
            for (int i = up; i <= down; i++) res.push_back(matrix[i][right]);
            if (--right < left) break;
            for (int i = right; i >= left; i--) res.push_back(matrix[down][i]);
            if (--down < up) break;
            for (int i = down; i >= up; i--) res.push_back(matrix[i][left]);
            if (++left > right) break;
        }
        return res;
    }
};