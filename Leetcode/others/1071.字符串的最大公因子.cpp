/**
对于字符串 S 和 T，只有在 S = T + ... + T（T 与自身连接 1 次或多次）时，我们才认定 “T 能除尽 S”。
返回最长字符串 X，要求满足 X 能除尽 str1 且 X 能除尽 str2。
*/
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        //求两个string长度的最大公约数即可
        if(str1+str2!=str2+str1)    return "";
        return str1.substr(0,gcd(str1.size(),str2.size()));
    }

    //欧几里得算法(辗转相除法)求最大公约数
    int gcd(int a,int b)
    {
        return b==0?a:gcd(b,a%b);
    }
};