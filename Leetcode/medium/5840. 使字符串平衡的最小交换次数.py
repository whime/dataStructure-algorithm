"""
给你一个字符串 s ，下标从 0 开始 ，且长度为偶数 n 。字符串 恰好 由 n / 2 个开括号 '[' 和 n / 2 个闭括号 ']' 组成。

只有能满足下述所有条件的字符串才能称为 平衡字符串 ：

字符串是一个空字符串，或者
字符串可以记作 AB ，其中 A 和 B 都是 平衡字符串 ，或者
字符串可以写成 [C] ，其中 C 是一个 平衡字符串 。
你可以交换 任意 两个下标所对应的括号 任意 次数。

返回使 s 变成 平衡字符串 所需要的 最小 交换次数。
"""


# 字符串每个位置的开括号数目大于等于闭括号数目
class Solution(object):
    def minSwaps(self, s):
        """
        :type s: str
        :rtype: int
        """
        n=len(s)
        left=right=0
        count=0
        for ch in s:
            if ch=="[":
                left+=1
            else:
                right+=1
            # 交换
            if right>left:
                right-=1
                left+=1
                count+=1
        return count

