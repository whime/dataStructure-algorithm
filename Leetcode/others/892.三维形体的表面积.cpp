/**
在 N * N 的网格上，我们放置一些 1 * 1 * 1  的立方体。
每个值 v = grid[i][j] 表示 v 个正方体叠放在对应单元格 (i, j) 上。
请你返回最终形体的表面积。
*/
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int size=grid.size();
        int num,res=0;
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<size;j++)
            {
                num=grid[i][j];
                if(num>0)
                {
                    res+=2+(num<<2);
                    if(i>0) res-=min(num,grid[i-1][j])<<1;
                    if(j>0) res-=min(num,grid[i][j-1])<<1;
                }
            }
        }
        return res;
    }
};