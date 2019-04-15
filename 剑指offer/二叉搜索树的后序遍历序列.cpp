//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty()) return false;
		int len = sequence.size();
		int root = sequence[len - 1];
		int i = 0;
        vector<int> tmp1;
        vector<int> tmp2;
		while (sequence[i] < root)
		{
            tmp1.push_back(sequence[i]);
			i++;
		}
		while (sequence[i] > root)
		{
            tmp2.push_back(sequence[i]);
			i++;
		}
		if (i<len-1)    return false;
        bool left=true;
        bool right=true;
        if(!tmp1.empty())
        {
            left=VerifySquenceOfBST(tmp1);
        }
        if(!tmp2.empty())
        {
            right=VerifySquenceOfBST(tmp2);
        }
		return  left && right;
	}
};

//大牛的答案

public:
	bool VerifySquenceOfBST(vector<int> sequence)
	{
		int size = sequence.size();
		if (0 == size) return false;

		int i = 0;
		while (--size) {
			while (sequence[i++] < sequence[size]);
			while (sequence[i++] > sequence[size]);

			if (i < size) return false;

			i = 0;
		}

		return true;
	}
};
