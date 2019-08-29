"""
2019年秋季招聘京东安全工程师笔试题
problem：给定一个有着大小写字母的字符串，按下大写字母可以有同时按下shift+字母（算作两次按键）
以及使用caps Lock 切换两种方法，输出打完这个字符串最小的按键次数（根据印象描述，意思差不多）
我的解决思路:只要有连续的三个大写字母在一起，就可以采用按caps键的方法，能够减少按键次数
"""
#字符串长度
class Solution:
	def getLeastKeyTime(self):
		"""
		>>> so=Solution()
		>>> so.getLeastKeyTime()
		8
		"""
		n=int(input())
		#字符串
		s=input()

		i=0
		count=0
		while True:
			if s[i]>='a'and s[i]<='z':
				count+=1
			else:
				if s[i]>='A' and s[i]<='Z':
					tmp=i
					while tmp<n and s[tmp]<='Z' and s[tmp]>='A':
						tmp+=1
					#切换大小写和打下大写字母
					if tmp-i<=2:
						count+=(tmp-i)*2
					else:
						count+=(tmp-i)+2
					if tmp==n:
						count-=1
						break
					i=tmp-1
			i+=1
			if i>=n:
				break
		print(count)

if __name__ == '__main__':
	# so=Solution()
	# so.getLeastKeyTime()
	#使用python的doctest玩一玩，分别输入是6，AaAAAA
	import doctest
	doctest.testmod()
