/*
��Ŀ����
��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ�%20�������磬
���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��
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
				//��֪��Ϊʲôû�в����ڴ�Խ�����⣬����str������ڴ�Ƚϴ��
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