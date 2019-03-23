/*
题目描述
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
*/

//来自评论区
class Solution:
    def NumberOf1(self, n):
        # write code here
        count = 0
        if n < 0:
            n = n & 0xffffffff
        while n:
            count += 1
            n = (n - 1) & n
        return count

//自己写的
class Solution {
public:
     int  NumberOf1(int n) {
         if(n>0)
         {
             int count=0;
             while(n)
             {
                 if(n%2!=0) count+=1;
                 n/=2;
             }
             return count;
         }
         if(n<0)
         {
             int count=0;
             while(n)
             {
                 if(n%2==0) count+=1;
                 n/=2;
             }
             return 32-count;
         }
         return 0;
     }
};