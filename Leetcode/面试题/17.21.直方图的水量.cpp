//给定一个直方图(也称柱状图)，假设有人从上面源源不断地倒水，最后直方图能存多少水量?直方图的宽度为 1。
//单调栈，维护一个单调递减的栈，与LeetCode 42题是一样的
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int size=height.size();
        int res=0;;
        for(int i=0;i<size;i++)
        {
            //无法保持单调递减，元素出栈直到从栈底到栈顶保持递减
            while(!s.empty()&&height[s.top()]<height[i])
            {
                //记录要出栈元素的索引，用于计算水量的高度
                int index=s.top();
                while(!s.empty()&&height[s.top()]==height[index])
                {
                    s.pop();
                }
                if(!s.empty())
                {
                    int h=min(height[i],height[s.top()]);
                    res+=(h-height[index])*(i-s.top()-1);
                }
            }
            //栈为空的话直接入栈，该元素为当前的最大高度
            s.push(i);
        }
        return res;
    }
};