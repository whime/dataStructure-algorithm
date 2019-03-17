#include<vector>
using namespace std;
/*
题目描述
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，
判断数组中是否含有该整数。
*/
//暴力求解
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

//另一种解法比较高效
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
