/**
给定一个单词列表，我们将这个列表编码成一个索引字符串 S 与一个索引列表 A。
例如，如果这个列表是 ["time", "me", "bell"]，我们就可以将其表示为 S = "time#bell#" 和 indexes = [0, 2, 5]。
对于每一个索引，我们可以通过从字符串 S 中索引的位置开始读取字符串，直到 "#" 结束，来恢复我们之前的单词列表。
那么成功对给定单词列表进行编码的最小字符串长度是多少呢？
*/
//方法1
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        //反转字符串
        for(string &word:words)
        {
            reverse(word.begin(),word.end());
        }
        sort(words.begin(),words.end());
        int res=0;
        for(int i=0;i<words.size()-1;i++)
        {
            int size=words[i].size();
            //被包含的字符串则跳过
            if(words[i]==words[i+1].substr(0,size)) continue;
            res+=size+1;
        }
        res+=words.back().size()+1;
        return res;
    }
};
//方法2
class Solution {
public:
    static bool isLonger(string &s1,string &s2)
    {
        return s1.size()>s2.size();
    }

    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(),words.end(),isLonger);//按长度从大到小排序

        string choosenString="";//保存当前的压缩结果
        int res=0;
        for(int i=0;i<words.size();i++)
        {
            if(choosenString.find(words[i]+"#")==string::npos)//找不到则为新单词
            {
                res+=words[i].size()+1;
                choosenString.append(words[i]+"#");
            }
        }
        return res;
    }

};
//也可以用字典树做