// 使用位运算还可以达到 O(1) 空间复杂度
/**
根据 百度百科 ，生命游戏，简称为生命，是英国数学家约翰·何顿·康威在 1970 年发明的细胞自动机。
给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。每个细胞都具有一个初始状态：1 即为活细胞（live），或 0 即为死细胞（dead）。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：
如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
根据当前状态，写一个函数来计算面板上所有细胞的下一个（一次更新后的）状态。下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。
*/
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int cellCount=0;
        if(board.size()==0) return;
        int row=board.size(),col=board[0].size();
        vector<int> tmp;
        vector<vector<int>> new_state(row,tmp);
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(i>0)
                {
                    cellCount+=board[i-1][j];
                    if(j>0)    cellCount+=board[i-1][j-1];
                    if(j<col-1) cellCount+=board[i-1][j+1];
                }
                if(j>0) cellCount+=board[i][j-1];
                if(j<col-1) cellCount+=board[i][j+1];
                if(i<row-1)
                {
                    cellCount+=board[i+1][j];
                    if(j>0) cellCount+=board[i+1][j-1];
                    if(j<col-1) cellCount+=board[i+1][j+1];
                }
                if(board[i][j]==0&&cellCount==3)    new_state[i].push_back(1);
                else if(board[i][j]==1&&(cellCount==2||cellCount==3))  new_state[i].push_back(1);
                else new_state[i].push_back(0);

                cellCount=0;
            }
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                board[i][j]=new_state[i][j];
            }
        }
    }
};