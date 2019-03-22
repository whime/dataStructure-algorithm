/* 
题目描述
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，
 该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*/
//直接遍历求解
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int tmp;
        if(rotateArray.size()==0)
        {
            return 0;
        }https://www.nowcoder.com/questionTerminal/9f3231a991af4f55b95579b44b7a01ba
        else{
            int i;
            int len=rotateArray.size();
            for(i=0;i<len;i++)
            {
                tmp=rotateArray[i];
                if(tmp>rotateArray[i+1])
                    break;  
            }
            return rotateArray[i+1];
        }
        
    }
};
//类似折半查找，参照首赞答案
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
       int left=0,right=rotateArray.size()-1;
        int mid,min;
        if(rotateArray.size()==0) return 0;
        while(rotateArray[left]>=rotateArray[right])
        {
            mid=left+(right-left)/2;
            if(right-left==1)
            {
                min=rotateArray[right];
                break;
            }
            
            else if(rotateArray[left]>rotateArray[mid])
            {
                right=mid;
            }
            else if(rotateArray[left]<=rotateArray[mid])
            {
                left=mid;
                
            }
            else if(rotateArray[left]==rotateArray[mid]&&rotateArray[left]==rotateArray[right])
            {
                min=rotateArray[left];
                int i;
                for(i=left;i<=right;i++)
                {
                    if(min>rotateArray[i])
                    {
                        min=rotateArray[i];
                    }
                }
                break;
                
            }
            
        }
        
        return min;
    }
};
