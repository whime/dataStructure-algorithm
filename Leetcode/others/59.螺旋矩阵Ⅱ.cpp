/**
给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> row(n,0);
        vector<vector<int>> res(n,row);
        if(n==0)    return res;
        // int count=pow(n,2);
        int num=1;
        int left=0,right=n-1,up=0,down=n-1;
        int i;
        //逐个填充
        while(true)
        {
            for(i=left;i<=right;i++){res[up][i]=num;num++;}
            if(++up>down)   break;
            for(i=up;i<=down;i++){res[i][right]=num;num++;}
            if(--right<left)    break;
            for(i=right;i>=left;i--){res[down][i]=num;num++;}
            if(--down<up)   break;
            for(i=down;i>=up;i--){res[i][left]=num;num++;}
            if(++left>right)    break;
        }
        return res;
    }
};