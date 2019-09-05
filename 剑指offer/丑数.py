"""
题目描述
把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含质因子7。
习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
"""
# -*- coding:utf-8 -*-
class Solution:
	def GetUglyNumber_Solution(self, index):
		# 暴力求解空间不够，只能采用动态规划
		if index<7:return index
		else:
			result=[1]
			t2=t3=t5=0
			for i in range(1,index):
				result.append(min(result[t2]*2,min(result[t3]*3,result[t5]*5)))
				#三个条件都要判断，否则可能会出现重复数字
				if result[i]==result[t2]*2:
					t2+=1
				if result[i]==result[t3]*3:
					t3+=1
				if result[i]==result[t5]*5:
					t5+=1
			# print(result)
			return result[index-1]

if __name__ == '__main__':
	n=int(input("输入："))
	so=Solution()
	print(so.GetUglyNumber_Solution(n))


