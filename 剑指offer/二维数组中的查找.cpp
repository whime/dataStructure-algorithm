#include<vector>
using namespace std;
/*
��Ŀ����
��һ����ά�����У�ÿ��һά����ĳ�����ͬ����ÿһ�ж����մ����ҵ�����˳������
ÿһ�ж����մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ��������
�ж��������Ƿ��и�������
*/
//�������
class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int row, col;
		for (row = 0; row<array.size(); row++) {
			for (col = 0; col<array[row].size(); col++) {
				if (target == array[row][col]) {
					return true;
				}
			}
		}
		return false;
	}
};

//��һ�ֽⷨ�Ƚϸ�Ч
class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int row = array.size() - 1, col = 0;
		int collen = array[0].size() - 1;
		while (row >= 0 && col <= collen) {
			if (target<array[row][col])
			{
				row--;
			}
			else if (target>array[row][col])
			{
				col++;
			}
			else
				return true;
		}
		return false;
	}
};
