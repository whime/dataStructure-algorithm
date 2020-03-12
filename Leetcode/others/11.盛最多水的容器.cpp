/**
给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
说明：你不能倾斜容器，且 n 的值至少为 2。
*/

//双指针法，先取底最大的左右边缘的线段构成的面积，之后向两边找更优解。
//由于容器的高度有最短的线段的高度决定，所以每次向内移动较短的线段以求获得更高的容器高度。
class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size()<=1)    return 0;
        int i=0,j=height.size()-1;
        int res=0,h;
        while(i<j)
        {
            h=std::min(height[i],height[j]);
            res=std::max(res,(j-i)*h);
            if(height[i]<height[j])
            {
                i++;
            }
            else
                j--;
        }
        return res;
    }
};