/**
在给定的网格中，每个单元格可以有以下三个值之一：
值 0 代表空单元格；
值 1 代表新鲜橘子；
值 2 代表腐烂的橘子。
每分钟，任何与腐烂的橘子（在 4 个正方向上）相邻的新鲜橘子都会腐烂。
返回直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1。
*/
// 使用BFS，注意边界控制，通过计数新鲜橘子的个数为零返回。
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int dirs[2][4]={{-1,1,0,0},{0,0,1,-1}};
        queue<pair<int,int>> q;
        int count=0,time=0;
        int col=grid[0].size(),row=grid.size();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
                else if(grid[i][j]==1)
                    count++; //统计新鲜的橘子的个数
            }
        }
        if(count==0)    return 0;
        //BFS
        int size,x,y;
        while(!q.empty())
        {
            size=q.size();
            time++;
            for(int i=0;i<size;i++)
            {
                auto cur=q.front();
                q.pop();
                for(int j=0;j<4;j++)
                {
                    //pair使用first,second 访问
                    x=cur.first+dirs[0][j];
                    y=cur.second+dirs[1][j];
                    if(x<row&&y<col&&x>=0&&y>=0)
                    {
                        if(grid[x][y]==1)
                        {
                            grid[x][y]=2;
                            q.push({x,y});
                            count--;
                        }
                    }
                }
                if(count==0)    return time;
            }
        }
        return -1;
    }
};