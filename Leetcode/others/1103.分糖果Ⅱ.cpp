/**
排排坐，分糖果。
我们买了一些糖果 candies，打算把它们分给排好队的 n = num_people 个小朋友。
给第一个小朋友 1 颗糖果，第二个小朋友 2 颗，依此类推，直到给最后一个小朋友 n 颗糖果。
然后，我们再回到队伍的起点，给第一个小朋友 n + 1 颗糖果，第二个小朋友 n + 2 颗，依此类推，直到给最后一个小朋友 2 * n 颗糖果。
重复上述过程（每次都比上一次多给出一颗糖果，当到达队伍终点后再次从队伍起点开始），直到我们分完所有的糖果。注意，就算我们手中的剩下糖果数不够（不比前一次发出的糖果多），这些糖果也会全部发给当前的小朋友。
返回一个长度为 num_people、元素之和为 candies 的数组，以表示糖果的最终分发情况（即 ans[i] 表示第 i 个小朋友分到的糖果数）。
*/
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        //将每次的分配结果组织成一个二维表，转化为求二维表每一列的和
        int sum=num_people*(num_people+1)/2;//第一行的和
        int end=num_people;//每一行的最后一个元素大小
        int row=1;//计算总共能分配多少行，最后一行可能无法分配完全，独立处理

        while(sum<candies)
        {
            end+=num_people;
            sum=end*(end+1)/2;
            row++;
        }

        vector<int> res;
        int ans=0;
        //使用等差数列求和公式求完整分配的行的每一列的和
        for(int i=1;i<=num_people;i++)
        {
            int start=i;
            ans=(2*start+(row-2)*num_people)*(row-1)/2;
            res.push_back(ans);
            candies-=ans;
        }
        //不完整分配的最后一行的起始分配个数
        int start=(row-1)*num_people+1;
        int i=0;
        //最后一行独立分配
        while(candies)
        {
            if(candies>start)
            {
                candies-=start;
                res[i]+=start;
            }
            else
            {
                res[i]+=candies;
                candies=0;
            }
            i++;
            start+=1;
        }
        return res;
    }
};