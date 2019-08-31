# -*- coding:utf-8 -*-
class Solution:
	def PrintMinNumber(self, numbers):
		#先排序，再输出
		from  functools import cmp_to_key
		numbers=sorted(numbers,key=cmp_to_key(self.lessThan))
		result=''
		for num in numbers:
			result+=str(num)
		print(result)
		return result
	#定义一个比较函数
	def lessThan(self,num1,num2):
		"""
		转换成str,逐个字符比较，较小的数先到达尾部之后，说明较小的数是较大的数的前缀
		将较小的数的下标索引取回0，重新开始比较
		若同时到达尾部返回索引0，说明较大的数是较小的数的重复叠加，如32和3232
		对最终的结果无影响，哪个在前都可以，返回零
		:param num1:
		:param num2:
		:return:
		"""
		if num1==num2:
			return 0
		num1=str(num1)
		num2=str(num2)
		numIter1=numIter2=0
		while True:
			if num1[numIter1]<num2[numIter2]:
				return -1
			elif num1[numIter1]>num2[numIter2]:
				return 1
			else:
				if numIter1==len(num1)-1:
					numIter1=-1
				if numIter2==len(num2)-1:
					numIter2=-1
				if numIter1==numIter2==-1:
					return 0
				numIter1+=1
				numIter2+=1

#讨论区里更加精简的解法，自愧不如
#这第二个方法在python3.6.6可以运行，在牛客网的py2.7.3无法通过
def solution(numbers):
	from functools import cmp_to_key
	numbers=sorted(numbers,key=cmp_to_key(lambda x,y:-1 if (str(x)+str(y))<(str(y)+str(x))\
		else (1 if (str(x)+str(y))>(str(y)+str(x)) else 0)))
	for num in numbers:
		print(num,end='')

if __name__ == '__main__':
	so=Solution()
	so.PrintMinNumber([3,32,321])
	# solution([3,32,321])
