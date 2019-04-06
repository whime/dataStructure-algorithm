/*输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈
序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）*/

//牛客网上最经典的解法，简洁高效
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size() == 0) return false;
        vector<int> stack;
        for(int i = 0,j = 0 ;i < pushV.size();){
            stack.push_back(pushV[i++]);
            while(j < popV.size() && stack.back() == popV[j]){
                stack.pop_back();
                j++;
            }      
        }
        return stack.empty();
    }
};

//自己实现的垃圾代码，在牛客上可过，在自己vs2017 ，66行上报错：Expression: can't decrement vector iterator before begin

#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {

        int startNum = popV.front();
        set<int> popNums;

        vector<int>::iterator it1 = pushV.end() - 1;
        vector<int>::iterator it2 = popV.begin() + 1;
        for (; it1 >= pushV.begin(); it1--)
        {
            //等于begin时，break,不能向下减迭代器了
            if (*it1 == startNum)
            {
                popNums.insert(startNum);
                break;
            }
            else if (it1 == pushV.begin())
            {
                //使用这个而不是下面注释的那行，否则对于下面的特定测试用例编译不过，不允许begin()-1
                return false;
            }
            else    popNums.insert(*it1);

        }
        //if (it1 < pushV.begin())    return false;
        if (it1 != pushV.begin())    it1--;
        for (it2 = popV.begin() + 1; it2 < popV.end(); it2++)
        {
            if (popNums.count(*it2) == 0 && *it1 != *it2)
                return false;
            else
            {
                if (*it1 == *it2)
                {
                    popNums.insert(*it1);
                    if (it1 == pushV.begin())   return true;
                    it1--;
                }
            }
        }
        return true;

    }
};