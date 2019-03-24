/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数
位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，
偶数和偶数之间的相对位置不变。*/

//STL库的stable_partition函数的第三个参数为函数指针，判断每个元素是否为真，true则放在数组前面，
//否则放在后面

#include<algorithm>
class Solution {

public:
    void reOrderArray(vector<int> &array) {
        stable_partition(array.begin(), array.end(), [](int i){return i % 2 == 1;});
    }
};



//类似插入排序的实现
class Solution {

public:
    void reOrderArray(vector<int> &array) {
   
        int length=array.size();
        int tmp;
        for(int i=0;i<length;i++)
        {
            if(array[i]%2)
            {
                tmp=array[i];
                int j;
                for(j=i-1;j>=0;j--)
                {
                    if(array[j]%2==0)
                    {
                        array[j+1]=array[j];
                    }
                    else
                    {
                        break;
                    }
                }
                array[j+1]=tmp;
            }
        }
    }
};

