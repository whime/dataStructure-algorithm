"""
题目描述
在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现
一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.
"""
# -*- coding:utf-8 -*-
class Solution:
	def FirstNotRepeatingChar(self, s):
		# write code here
		if s=="":
			return -1
		procBefore=[]
		uniAlpha={}
		i=0
		for letter in s:
			if letter not in procBefore:
				procBefore.append(letter)
				uniAlpha[letter]=i
			else:
				if letter in uniAlpha.keys():
					uniAlpha.pop(letter)
			i+=1
		if not uniAlpha:
			return -1
		res=sorted(uniAlpha.items(),key=lambda x:x[1])
		# print(res[0][1])
		return res[0][1]

#讨论区简洁的答案
class Solution2:
	def FirstNotRepeatingChar(self, s):
		return s.index(list(filter(lambda c:s.count(c)==1,s))[0]) if s else -1

if __name__ == '__main__':
	so=Solution()
	so.FirstNotRepeatingChar('googgle')
