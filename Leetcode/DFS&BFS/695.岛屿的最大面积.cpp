

//看评论区都用的dfs，还是不太熟练，典型的dfs题目啊
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;//保存当前连续的1的坐标
        int area=0,res=0;

        //BFS,虽然没递归，当时使用了队列，内存占用比较大
        for(int x=0;x<grid.size();x++)
        {
            for(int y=0;y<grid[0].size();y++)
            {
                if(grid[x][y]==1)
                {
                    q.push(make_pair(x,y));
                    area++;
                    while(!q.empty())
                    {
                        auto point=q.front();
                        q.pop();
                        grid[point.first][point.second]=0;

                        if(point.first>0&&grid[point.first-1][point.second])
                            {area++;grid[point.first-1][point.second]=0;q.push(make_pair(point.first-1,point.second));}
                        if(point.first<grid.size()-1&&grid[point.first+1][point.second])
                            {area++;grid[point.first+1][point.second]=0;q.push(make_pair(point.first+1,point.second));}
                        if(point.second>0&&grid[point.first][point.second-1])
                            {area++;grid[point.first][point.second-1]=0;q.push(make_pair(point.first,point.second-1));}
                        if(point.second<grid[0].size()-1&&grid[point.first][point.second+1])
                            {area++;grid[point.first][point.second+1]=0;q.push(make_pair(point.first,point.second+1));}                        }
                    res=max(res,area);
                    area=0;
                }

            }
        }
        return res;
    }
};

//经典的DFS解法
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res=0;
        int m=grid.size(),n=grid[0].size();
        //试试匿名函数
        function<int(int,int)> dfs=[&](int x,int y){
            if(x<0||x>=m||y<0||y>=n||grid[x][y]==0) return 0;
            grid[x][y]=0;//访问过置为0
            return 1+dfs(x-1,y)+dfs(x+1,y)+dfs(x,y-1)+dfs(x,y+1);
        };
        for(int x=0;x<m;x++)
        {
            for(int y=0;y<n;y++)
            {
                if(grid[x][y]==1)
                    res=max(res,dfs(x,y));
            }
        }
        return res;
    }
};