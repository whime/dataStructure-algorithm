"""
在太空深处，生活着这样一群外星人，他们左手有4个手指，右手有5个手指，所以自然地，他们习惯于采用9进制记数。
不过，这些外星人还没有点亮“计算机”科技，所以向地球上的你发出了求助，希望你帮他们设计一款可以用来完成9进制加法的程序。
"""

#
# 接收两个表示9进制数的字符串，返回表示它们相加后的9进制数的字符串
# @param num1 string字符串 第一个加数
# @param num2 string字符串 第二个加数
# @return string字符串
#
class Solution:
    def add(self, num1, num2):
        # write code here
        len1 = len(num1)
        len2 = len(num2)
        i = len1
        j = len2
        tmp = 0
        jinwei = 0
        firstpart = ''
        secondpart = ''
        if '.' not in num1:
            if '.' not in num2:
                pass
            else:
                secondpart = num2.split('.')[1]
                j=num2.rfind('.')
        else:
            if '.' not in num2:
                secondpart = num1.split('.')[1]
                i=num1.rfind('.')
            else:
                # 都包含小数位，先计算小数位部分
                i=len1;j=len2
                size1=i-num1.find('.')
                size2=j-num2.find('.')
                minsize=min(size1,size2)
                i-=1
                j-=1
                while minsize!=size1:
                    size1-=1
                    tmp = int(num1[i]) + jinwei
                    jinwei = tmp // 9
                    secondpart += str(tmp % 9)
                    i -= 1
                while minsize!=size2:
                    size2-=1
                    tmp = int(num2[j]) + jinwei
                    jinwei = tmp // 9
                    secondpart += str(tmp % 9)
                    j -= 1
                while num1[i] != '.' and num2[j] != '.':
                    tmp = int(num1[i]) + int(num2[j]) + jinwei
                    secondpart += str(tmp % 9)
                    jinwei = tmp // 9
                    i -= 1
                    j -= 1

                secondpart=secondpart[::-1]
        i-=1
        j-=1
        # 计算整数部分
        while i>=0 and j>=0:
            tmp=int(num1[i])+int(num2[j])+jinwei
            firstpart+=str(tmp%9)
            jinwei=tmp//9
            i -= 1
            j -= 1
        while i>=0:
            tmp = int(num1[i]) + jinwei
            jinwei = tmp // 9
            firstpart += str(tmp % 9)
            i -= 1
        while j>=0:
            tmp = int(num2[j]) + jinwei
            jinwei = tmp // 9
            firstpart += str(tmp % 9)
            j -= 1
        if jinwei:
            firstpart+=str(jinwei)
        firstpart=firstpart[::-1]
        if secondpart=='':
            return firstpart
        else:
            return firstpart+'.'+secondpart

if __name__ == '__main__':
    so=Solution()
    print(so.add('0.25','0.75'))