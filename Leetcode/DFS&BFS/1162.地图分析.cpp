/**
你现在手里有一份大小为 N x N 的『地图』（网格） grid，上面的每个『区域』（单元格）都用 0 和 1 标记好了。其中 0 代表海洋，1 代表陆地，
你知道距离陆地区域最远的海洋区域是是哪一个吗？请返回该海洋区域到离它最远的陆地区域的距离。
我们这里说的距离是『曼哈顿距离』（ Manhattan Distance）：(x0, y0) 和 (x1, y1) 这两个区域之间的距离是 |x0 - x1| + |y0 - y1| 。
如果我们的地图上只有陆地或者海洋，请返回 -1。
*/
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int size=grid.size();
        int seaCount=0;
        int dirs[2][4]={{-1,1,0,0},{0,0,-1,1}};
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<size;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                }
                else   seaCount+=1;
            }
        }

        if(seaCount==0) return -1;
        int x,y,distance=0;
        while(!q.empty())
        {
            distance++;
            int qsize=q.size();
            for(int i=0;i<qsize;i++)
            {
                auto area=q.front();
                q.pop();
                for(int k=0;k<4;k++)
                {
                    x=area.first+dirs[0][k];
                    y=area.second+dirs[1][k];
                    if(x<0||y<0||x>=size||y>=size)  continue;
                    if(grid[x][y]==0)
                    {
                        grid[x][y]=1;
                        seaCount--;
                        q.push({x,y});
                    }
                }
                if(seaCount==0) return distance;;
            }
        }
        return -1;
    }
};