/**
给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。
滑动窗口每次只向右移动一位。返回滑动窗口中的最大值。

*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;//双端队列保存nums元素的索引
        int len=nums.size();
        int i=0;
        vector<int> res;
        for(;i<len;i++)
        {
            //如果新检索的元素大于队列的元素，则从队列后面删除该记录，继续向前比较
            //直到队列为空或者队列保存的索引所对应的元素依次递减
            while(!q.empty()&&nums[q.back()]<nums[i])
            {
                q.pop_back();
            }
            q.push_back(i);//保存进队尾

            //若队列元素位置之差等于k,则将队首元素移除
            if(i-q.front()==k)
            {
                q.pop_front();
            }
            //从第k-1个元素时保存最大值
            if(i>=k-1)
            {
                res.push_back(nums[q.front()]);
            }
        }
        return res;
    }
};