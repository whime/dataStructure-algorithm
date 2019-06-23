/*
����һ���ַ���,���ֵ����ӡ�����ַ������ַ����������С����������ַ���abc,���ӡ�����ַ�a,b,c�������г����������ַ���abc,acb,bac,bca,cab��cba��
����һ���ַ���,���Ȳ�����9(�������ַ��ظ�),�ַ�ֻ������Сд��ĸ��

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