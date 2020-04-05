/**
实现 int sqrt(int x) 函数。
计算并返回 x 的平方根，其中 x 是非负整数。
由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
*/
class Solution {
public:
    int mySqrt(int x) {
        if(x<2) return x;
        int left=0,right=x;
        int res;
        while(left<right-1)
        {
            res=(left+right)/2;
            if(pow(res,2)<x)    left=res;
            else if(pow(res,2)>x)   right=res;
            else return res;
        }
        return left;
    }
};