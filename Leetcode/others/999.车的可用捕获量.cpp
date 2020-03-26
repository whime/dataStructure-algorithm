/**
在一个 8 x 8 的棋盘上，有一个白色车（rook）。也可能有空方块，白色的象（bishop）和黑色的卒（pawn）。它们分别以字符 “R”，“.”，“B” 和 “p” 给出。大写字符表示白棋，小写字符表示黑棋。
车按国际象棋中的规则移动：它选择四个基本方向中的一个（北，东，西和南），然后朝那个方向移动，直到它选择停止、到达棋盘的边缘或移动到同一方格来捕获该方格上颜色相反的卒。另外，车不能与其他友方（白色）象进入同一个方格。
返回车能够在一次移动中捕获到的卒的数量。
*/
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int size=board.size();
        int i,j;
        int dir[2][4]={{-1,1,0,0},{0,0,-1,1}};
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                if(board[i][j]=='R')
                {
                    int res=0;
                    for(int k=0;k<4;k++)
                    {
                        int x=i,y=j;
                        while(true)
                        {
                            x+=dir[0][k];
                            y+=dir[1][k];
                            if(x<0||x>=8||y<0||y>=8||board[x][y]=='B')
                            {
                                break;
                            }
                            if(board[x][y]=='p')
                            {
                                res++;
                                break;
                            }
                        }
                    }
                    return res;
                }
            }
        }
        return 0;
    }
};