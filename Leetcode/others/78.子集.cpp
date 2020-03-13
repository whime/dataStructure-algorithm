/**
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
说明：解集不能包含重复的子集。
*/
//方法1
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back(vector<int>());

        //遍历所有元素，每遇到一个元素就在现有子集基础上都加上元素i,再并入res
        for(int i=0;i<nums.size();i++)
        {
            int size=res.size();
            for(int j=0;j<size;j++)
            {
                vector<int> tmp(res[j]);//要创建新的拷贝
                tmp.push_back(nums[i]);
                res.push_back(tmp);
            }
        }
        return res;
    }
};

//方法2
//使用评论区位运算方法，所有子集个数为2^n，n为元素个数，可以转换为0~2^n-1这些数中1的位置所对应的元素构成的子集的集合。
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();//元素个数
        int count=pow(2,n);//子集个数
        int number=0,i;
        vector<vector<int>> res;
        while(number<count)
        {
            i=n-1;//表示当前考虑取与不取第几个元素
            vector<int> tmp;
            int tmp_num=number;
            while(tmp_num>0)
            {
                if(tmp_num&1==1)//最后一位为1表示取
                {
                    tmp.push_back(nums[i]);
                }
                tmp_num>>=1;
                i--;
            }
            number++;
            res.push_back(tmp);
        }
        return res;
    }
};

//方法3，回溯法
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //回溯法
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(res,tmp,0,nums);

        return res;
    }
    void dfs(vector<vector<int>>& res,vector<int>& tmp,int start,vector<int>& nums)
    {
        res.push_back(tmp);
        for(int i=start;i<nums.size();i++)
        {
            tmp.push_back(nums[i]);
            dfs(res,tmp,i+1,nums);
            tmp.pop_back();
        }
    }
};