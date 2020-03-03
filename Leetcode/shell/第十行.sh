#给定一个文本文件 file.txt，请只打印这个文件中的第十行。
#说明:
#1. 如果文件少于十行，你应当输出什么？
#2. 至少有三种不同的解法，请尝试尽可能多的方法来解题。

# tail -n +10 表示从第十行开始输出
tail -n+10 file.txt|head -n 1
#awk 'NR==10' file.txt
#sed -n '10p' file.txt