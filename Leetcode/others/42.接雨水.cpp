//给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
//方法一，记录每个柱子的左右最大高度，每次取两个中的较小者。
class Solution {
public:
    int trap(vector<int>& height) {
        int size=height.size();
        vector<int> leftBound(size,0);//每个柱子的左边最大高度
        vector<int> rightBound(size,0);//每个柱子的左边最大高度
        for(int i=1;i<size;i++)
        {
            leftBound[i]=max(leftBound[i-1],height[i-1]);
        }
        for(int i=size-2;i>=0;i--)
        {
            rightBound[i]=max(rightBound[i+1],height[i+1]);
        }
        int res=0;
        //每个位置所能容纳的雨水量由左右的最大高度的较小值决定
        for(int i=0;i<size;i++)
        {
            int bound=min(rightBound[i],leftBound[i]);
            res+=(bound-height[i])<0?0:(bound-height[i]);
        }
        return res;
    }
};
// 双指针
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0)    return 0;
        int left=0,right=height.size()-1;
        int leftMax=height[left],rightMax=height[right];
        int res=0;
        while(left<right)
        {
            if(height[left]<height[right])
            {
                if(height[left]>leftMax)    leftMax=height[left];
                else
                {
                    res+=leftMax-height[left];
                }
                left++;
            }
            else
            {
                if(height[right]>rightMax)  rightMax=height[right];
                else
                {
                    res+=rightMax-height[right];
                }
                right--;
            }
        }
        return res;
    }
};