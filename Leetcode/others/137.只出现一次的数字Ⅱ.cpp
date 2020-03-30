/**
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。
*/
//每次取每个数的一位二进制位，若1的个数不能整除3，则目标元素对应的二进制位为1.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int i=0;i<32;i++)
        {
            int mask=1<<i;
            int count=0;
            for(int j=0;j<nums.size();j++)
            {
                if(((unsigned)nums[j]&mask)>0)   count++;
            }
            if(count%3!=0)  res|=mask;
        }
        return res;
    }
};