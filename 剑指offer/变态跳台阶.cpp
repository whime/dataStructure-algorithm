/*
题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/


//菜鸡的解法
class Solution {
public:
    int jumpFloorII(int number) {
        int* steps=new int[number]{0};
        steps[0]=1;//只有1个台阶
        steps[1]=2;
        for(int i=2;i<number;i++)
        {
            steps[i]=1;
            for(int j=0;j<i;j++)
            {
                steps[i]+=steps[j];
            }
           
        }
        return steps[number-1];//加1代表一次跳完n阶到达终点的情况，也是一种跳法。
    }
};

//大牛的解法
class Solution {
public:
    int jumpFloorII(int number) {
        return 1<<(number-1);
    }
};