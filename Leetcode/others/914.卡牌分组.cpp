/**
给定一副牌，每张牌上都写着一个整数。
此时，你需要选定一个数字 X，使我们可以将整副牌按下述规则分成 1 组或更多组：
每组都有 X 张牌。
组内所有的牌上都写着相同的整数。
仅当你可选的 X >= 2 时返回 true。
*/
// 求各个数出现的次数之间的最大公因数
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int size=deck.size();
        if(size<2)  return false;
        map<int,int> mapping;

        for(int i=0;i<size;i++)
        {
            mapping[deck[i]]++;
        }
        int res=mapping.begin()->second;
        for(auto iter=mapping.begin();iter!=mapping.end();iter++)
        {
            res=gcd(res,iter->second);
        }
        return res>=2;
    }
};