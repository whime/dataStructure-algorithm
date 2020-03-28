/**
给定一个偶数长度的数组，其中不同的数字代表着不同种类的糖果，每一个数字代表一个糖果。
你需要把这些糖果平均分给一个弟弟和一个妹妹。返回妹妹可以获得的最大糖果的种类数。
*/
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int size=candies.size();
        unordered_map<int,int> s;
        for(int i=0;i<size;i++)
        {
            if(s.count(candies[i])==0)
            {
                s[candies[i]]=1;
            }
        }
        int typeCount=s.size();
        return min(typeCount,size/2);
    }
};

