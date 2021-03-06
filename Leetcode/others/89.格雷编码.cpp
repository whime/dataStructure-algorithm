/**
格雷编码是一个二进制数字系统，在该系统中，两个连续的数值仅有一个位数的差异。
给定一个代表编码总位数的非负整数 n，打印其格雷编码序列。格雷编码序列必须以 0 开头。
*/
class Solution {
public:
    vector<int> grayCode(int n) {
        int size=pow(2,n);
        vector<int> res;
        for(int i=0;i<size;i++)
        {
            res.push_back(i^(i>>1));
        }
        return res;
    }
};