# -*- coding:utf-8 -*-
class Solution:
	def NumberOf1Between1AndN_Solution(self, n):
		# write code here
		#来源于讨论区优秀回答
		count=0;i=1
		while i<=n:
			a=n//i
			b=n%i
			count+=(a+8)//10 * i+(a%10==1) * (b+1)
			i*=10
		return count

