# 找出1-9组成的字符串里由三个字符组成的最大的三位数

s=input()
max_num=int(s[:3])
for i in range(1,len(s)-2):
    print(int(s[i:i+3]))
    if int(s[i:i+3])>=max_num:
        max_num=int(s[i:i+3])
print(max_num)