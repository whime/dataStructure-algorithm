/*
题目描述
请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，
当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/
class Solution {
public:
	void replaceSpace(char *str, int length) {
		int i, spacecount = 0;
		for (i = 0; i<length; i++)
		{
			if (*(str + i) == ' ')    spacecount++;
		}
		int j = length + spacecount * 2 - 1;
		i = length - 1;
		for (; i >= 0; i--)
		{
			if (*(str + i) != ' ')
			{
				//不知道为什么没有产生内存越界问题，可能str分配的内存比较大吧
				*(str + j) = *(str + i);
				j--;
			}
			else
			{
				str[j--] = '0';
				str[j--] = '2';
				str[j--] = '%';
			}
		}
	}
};