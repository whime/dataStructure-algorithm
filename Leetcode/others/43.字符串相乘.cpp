//给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
/**
说明：
num1 和 num2 的长度小于110。
num1 和 num2 只包含数字 0-9。
num1 和 num2 均不以零开头，除非是数字 0 本身。
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
*/
class Solution {
public:
    string multiply(string num1, string num2) {
        int size1=num1.size(),size2=num2.size();
        // 如果有一个乘数为0，返回“0”
        if(num1[0]=='0'||num2[0]=='0')  return string("0");
        string s="";
        int tmp[220]={0};//总的乘积结果不超过110*2长度
        int end=220,begin=end;
        int carry=0,sum=0;//carry保存进位，sum保存每个数位的新的计算结果

        //从后面往前填充数组
        for(int i=size2-1;i>=0;i--)
        {
            end--;
            begin=end;
            for(int j=size1-1;j>=0;j--)
            {
                sum=(num1[j]-'0')*(num2[i]-'0')+carry+tmp[begin];
                tmp[begin]=sum%10;

                carry=sum/10;
                begin--;
            }
            if(carry)
            {
                tmp[begin]=carry;
                carry=0;
            }
        }
        if(tmp[begin]==0)   begin++;//忽略多余的前置0
        for(int i=begin;i<220;i++)
        {
            s.push_back(tmp[i]+'0');//保存在string
        }
        return s;
    }
};