//给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
//你可以假设数组是非空的，并且给定的数组总是存在多数元素。

// O(nlgn)已经是最差的时间复杂度了
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};

//遍历计数的方法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mapping;
        for(int num:nums)
        {
            if(mapping.count(num)==0)
                mapping[num]=1;
            else
                mapping[num]++;
            if(mapping[num]>nums.size()/2)
                return num;
        }
        return 0;
    }
};

//摩尔投票法，基本思路是每次抵消掉等数量的众数和非众数，或者非众数之间相互抵消，最后剩下的就是众数
//前提是众数个数占了一半以上，时间复杂度为O(N)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0,res;
        for(int num:nums)
        {
            if(count==0)
            {
                res=num;//假设num即为众数
                count++;
            }
            else
            {
                if(res!=num)
                    count--;
                else    count++;
            }
        }
        return res;
    }
};