/*输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下4 X 4矩阵：
 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.*/

//模拟顺时针取数
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int columnCount=matrix[0].size();
        int rowCount=matrix.size();
        vector<int> arr;
        for(int j=0;j<=matrix.size()/2;j++)
        {
            int i=j;
            if(j>(columnCount-1)) break;
            if(j>(rowCount-1)) break;
            for(;i<columnCount;i++)
            {
                arr.push_back(matrix[j][i]);
            }
            for(int k=j+1;k<rowCount;k++)
            {
                arr.push_back(matrix[k][columnCount-1]);
            }
            
            if(j==(rowCount-1)) break;
  			if (j == (columnCount - 1))  break;
            for(int m=columnCount-2;m>=j;m--)
            {
                arr.push_back(matrix[rowCount-1][m]);
            }
           
            for(int n=rowCount-2;n>j;n--)
            {
                arr.push_back(matrix[n][j]);
            }
            rowCount--;
            columnCount--;
        }
        return arr;
    }
};