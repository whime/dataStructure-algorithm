/*
题目描述
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠
地覆盖一个2*n的大矩形，总共有多少种方法？
*/
//还是递归
class Solution {
public:
    int rectCover(int number) {
        if(number<3) return number;
        else
        {
            return rectCover(number-1)+rectCover(number-2);
        }
    }
};
//非递归
class Solution {
public:
    int rectCover(int number) {
        if(number<3) return number;
        else
        {
            int front=2,current=3;
            for(int i=4;i<=number;i++)
            {
                current+=front;
                front=current-front;
            }
            return current;
        }
    }
};