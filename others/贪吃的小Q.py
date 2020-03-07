'''
小Q的父母要出差N天，走之前给小Q留下了M块巧克力。小Q决定每天吃的巧克力数量不少于前一天吃的一半，
但是他又不想在父母回来之前的某一天没有巧克力吃，请问他第一天最多能吃多少块巧克力
input:
每个输入包含一个测试用例。
每个测试用例的第一行包含两个正整数，表示父母出差的天数N(N<=50000)和巧克力的数量M(N<=M<=100000)。
output:
输出一个数表示小Q第一天最多能吃多少块巧克力。

eg:3 7
   4
'''
#使用二分查找，不断查找第一天吃的巧克力数量
data = input().split()
n = int(data[0])
m = int(data[1])
# 计算第一天吃mid块巧克力所需要的总的巧克力数量
def calSum(mid, day):
    res = 0
    for i in range(day):
        res += mid
        mid = (mid + 1) // 2 #向上取整
    return res

left = 1
right = m
while (left <= right):
    mid = (left + right) // 2
    res = calSum(mid, n)
    if res < m:
        left = mid + 1
    elif res > m:
        right = mid - 1
    else:
        right = mid
        break
print(right)