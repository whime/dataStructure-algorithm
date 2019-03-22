
//现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
n<=39


//直接递归法，可以保存计算后的值避免重复计算
class Solution {
public:
    int Fibonacci(int n) {
        if(n==1||n==2) return 1;
        else if(n==0) return 0;
        else return Fibonacci(n-1)+Fibonacci(n-2);
    }
};
//动态规划
class Solution {
public:
    int Fibonacci(int n) {
        if(n==0||n==1) return n;
        else
        {
            int front=0,rear=1;
            while(n--)
            {
                rear+=front;
                front=rear-front;  
            }
            return  front;
        }
    }
};
