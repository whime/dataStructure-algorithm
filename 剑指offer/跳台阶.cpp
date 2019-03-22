/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法
（先后次序不同算不同的结果）。
*/

//看来我还是只会递归啊
class Solution {
public:
    int jumpFloor(int number) {
        
        if(number==1)    return 1;
        else if(number==2) return 2;
        else
        {
            return jumpFloor(number-1)+jumpFloor(number-2);
        }
    }
};
//类似Fabonacci数列的方法
class Solution {
public:
    int jumpFloor(int number) {
        if(number<0) return 0;
        else if(number==1||number==2)    return number;
        else
        {
            int f1=1,f2=2,tmp;
            for(int i=2;i<number;++i)
            {
                tmp=f1+f2;
                f1=f2;
                f2=tmp;
            }
            return f2;
            
        }
    }
};