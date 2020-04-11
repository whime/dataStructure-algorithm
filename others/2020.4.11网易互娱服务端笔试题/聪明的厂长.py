"""
厂长阿雄需要根据工厂里每个员工的劳动技能等级来分配每天的工作任务。
一个工作任务只能由劳动技能等级大于等于该任务难度的员工来完成，且同一天里一个员工只能对应一个工作任务，一个工作任务只能由一个员工来完成。
员工i的劳动技能等级由整数Wi来表示，工作任务i的任务难度由整数Ti，来表示。
聪明的你能帮助阿雄分配今天的工作任务么？
"""
n=int(input())
w=list(map(lambda x:int(x),input().split(' ')))
t=list(map(lambda x:int(x),input().split(' ')))
m=int(input())

# 排序之后，由劳动技能最小的员工先选择任务，剩下可选的任务交给下一个较大劳动技能的员工选择
# 累乘每次可选择的任务即为所求
w.sort()
t.sort()
choice=0
index=0
flag=False
res=1
for i in w:
    while not flag and i>=t[index]:
        choice+=1
        index+=1
        if index==len(t):
            flag=True
    res*=choice
    choice-=1
print(res%m)
