#写一个 bash 脚本以统计一个文本文件 words.txt 中每个单词出现的频率。
#为了简单起见，你可以假设：
#words.txt只包括小写字母和 ' ' 。
#每个单词只由小写字母组成。
#单词间由一个或多个空格字符分隔。

# 先使用tr -s 去掉重复字符并替换空格为换行
# 再使用sort排序才能使uniq计数相邻的重复行
# 再使用sort -r逆序，左右列调换输出
cat words.txt|tr -s ' ' '\n'|sort|uniq -c|sort -r|awk '{print $2" "$1}'