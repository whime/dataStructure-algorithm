/**
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
示例
输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
*/
using namespace std;
#include<algorithm>
#include<cstdlib>
#include<ctime>
class Solution {
public:
    // static bool cmp(int a,int b)
    // {
    //     return a>b;
    // }
    int quickSort(int* data,int low,int high)
    {
        int randIndex=rand()%(high-low+1)+low;
        //快速排序,随机选取一个下标
        int tmp=data[randIndex];
        swap(data[low],data[randIndex]);

        //如下while嵌套循环超出时间限制，要求不严格的话可以用
        // while(low<high)
        // {
        //     while(low<high&&data[high]>tmp) high--;
        //     data[low]=data[high];
        //     while(low<high&&data[low]<tmp)  low++;
        //     data[high]=data[low];
        // }
        //data[low]=tmp;
        //return low;
        int i,j=low;
        for(i=low+1;i<=high;i++)
        {
            if(data[i]<tmp)
            {
                swap(data[i],data[++j]);
            }
        }
        swap(data[low],data[j]);
        return j;
    }
    int findKthMax(int *data,int low,int high,int k)
    {
        if(low==high)
            return data[low];
        //利用快速排序，将数组分为左小右大的两个数组，递归相比下面的方法要慢
        // int loc=quickSort(data,low,high);
        // if(loc==(k-1))    return data[loc];
        // else if(loc<(k-1))    return findKthMax(data,loc+1,high,k);
        // else return findKthMax(data,low,loc-1,k);
        while(true)
        {
            int pos=quickSort(data,low,high);
            if(pos==k-1)
            {
                return data[pos];
            }
            if(pos>k-1) high=pos-1;
            else    low=pos+1;
        }

    }
    int findKthLargest(vector<int>& nums, int k) {
        //直接全部排序，定位输出
        // sort(nums.begin(),nums.end(),Solution::cmp);
        // return nums[k-1];

        //需要使用随机数避免快排算法退化
        srand(time(NULL));
        int *data=nums.data();
        //注意high参数需要size-1
        return findKthMax(data,0,nums.size()-1,nums.size()-k+1);

    }
};