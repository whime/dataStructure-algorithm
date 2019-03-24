/*
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
*/

class Solution {
public:
    double Power(double base, int exponent) {
        int result=base;
        for(int i=1;i<exponent;i++)
        {
            result*=base;
        }
        if(exponent<0) return 1/Power(base,-exponent);
        else if(exponent==0) return 1;
        else return result;
    }
};

//快速幂方法
class Solution {
public:
    double Power(double base, int exponent) {
       int result=1;
       if(exponent>0)
       {
           while(exponent)
       {
           if(exponent&1)//取二进制的最后一位
               result*=base;
           base*=base;
           exponent>>=1;//移去最后一位
       }
           return result;
       }
        else if(exponent==0) return 1;
        else return 1/Power(base,-exponent);
    }
};