/**
给你一个整数数组 A，只有可以将其划分为三个和相等的非空部分时才返回 true，否则返回 false。
*/
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int size=A.size();
        int sum=std::accumulate(A.begin(),A.end(),0);
        if(sum%3!=0)    return false;

        int i=0,j=size-1,leftsum=A[0],rightsum=A[size-1];
        int avg=sum/3;
        bool res=false;
        while(i<j)
        {
            if(leftsum!=avg)
            {
                i++;
                leftsum+=A[i];
            }    
            if(rightsum!=avg)
            {
                j--;
                rightsum+=A[j];
            }   

            if(leftsum==avg&&rightsum==avg)
            {
                res=true;
                break;
            }
        }
        return res&&j-i>1;//注意处理和为0的情况
    }
};