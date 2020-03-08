//给定一个无序的整数数组，找到其中最长上升子序列的长度。

//O(N^2)方法
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size=nums.size();
        if(!size) return 0;
        //dp[i]表示以nums[i]为结尾的子序列的最长长度，最小为1
        int dp[size];
        for(int i=0;i<size;i++)
        {
            dp[i]=1;//默认最小为其本身，长度为1
            for(int j=i-1;j>=0;j--)
            {
                if(nums[j]<nums[i]&&dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                }
            }
        }

        int res=0;
        //查找dp中最大的数即为解
        for(int i=0;i<size;i++)
        {
            if(res<dp[i])
                res=dp[i];
        }
        return res;
    }
};

//O(NlgN)方法
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size=nums.size();
        if(size==0) return 0;
        int record[size];//record[i]表示长度为i+1的所有递增序列中的最小的尾元素
        record[0]=nums[0];
        int index=0,pos;
        for(int i=1;i<size;i++)
        {
            if(nums[i]>record[index])
            {//大于则可以将nums[i]接在长度为index的子序列前面，长度加一
                record[++index]=nums[i];
            }
            else
            {//否则将nums[i]二分查找插入到使整个序列保持递增的位置
                pos=BinarySearch(record,index+1,nums[i]);
                record[pos]=nums[i];
            }
        }
        return (index+1);
    }
    //二分查找插入的位置
    int BinarySearch(int *arr,int len,int value)
    {
        int left=0,right=len-1,mid;

        while(left<=right)
        {
            mid=(left+right)/2;
            if(arr[mid]<value)  left=mid+1;
            else if(arr[mid]>value) right=mid-1;
            else return mid;
        }
        return left;

    }
};

