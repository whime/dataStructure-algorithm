/*
输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。

*/


class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> list;
        if(!str.empty()&&str.length()>0)
        {
           Helper(str,0,list);
           sort(list.begin(),list.end());
        }   
        return list;
    }
    void Helper(string& str,int i,vector<string>& list)
    {
        if(i==str.length()-1)
        {
            if(!std::count(list.begin(),list.end(),str))
            {
                list.push_back(string(str));    
            }
        }
        else
        {
            for(unsigned int j=i;j<str.size();j++)
            {
                 swap(str,i,j);
                Helper(str,i+1,list);
                swap(str,i,j);
            }
        }
    }
    void swap(string &str,int i,int j)
    {
        if(i!=j)
        {
            char tmp=str[i];
            str[i]=str[j];
            str[j]=tmp;
        }
    }
};