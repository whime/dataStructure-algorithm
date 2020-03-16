/**
字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。比如，字符串aabcccccaaa会变为a2b1c5a3。
若“压缩”后的字符串没有变短，则返回原先的字符串。你可以假设字符串中只包含大小写英文字母（a至z）。
*/
class Solution {
public:
    string compressString(string S) {
        int size=S.length();
        if(size==0) return S;
        int count=1;
        string res;
        for(int i=0;i<size;i++)
        {
            if(i!=size-1&&S.at(i)==S.at(i+1))
            {
                count++;
                continue;
            }
            res.push_back(S[i]);
            res.append(to_string(count));
            count=1;
        }

        return res.size()<S.size()?res:S;
    }
};