/**
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> backets;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{')
            {
                backets.push(s[i]);
            }
            else
            {
                if(backets.size()!=0)//栈不为空
                {
                    if(s[i]==')'&&backets.top()!='(')   return false;
                    if(s[i]=='}'&&backets.top()!='{')   return false;
                    if(s[i]==']'&&backets.top()!='[')   return false;
                    backets.pop();
                }
                else return false;
            }
        }
        if(backets.size()!=0)   return false;
        return true;
    }
};