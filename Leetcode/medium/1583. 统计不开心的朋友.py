"""
给你一份 n 位朋友的亲近程度列表，其中 n 总是 偶数 。

对每位朋友 i，preferences[i] 包含一份 按亲近程度从高到低排列 的朋友列表。换句话说，排在列表前面的朋友与 i 的亲近程度比排在列表后面的朋友更高。每个列表中的朋友均以 0 到 n-1 之间的整数表示。

所有的朋友被分成几对，配对情况以列表 pairs 给出，其中 pairs[i] = [xi, yi] 表示 xi 与 yi 配对，且 yi 与 xi 配对。

但是，这样的配对情况可能会是其中部分朋友感到不开心。在 x 与 y 配对且 u 与 v 配对的情况下，如果同时满足下述两个条件，x 就会不开心：

x 与 u 的亲近程度胜过 x 与 y，且
u 与 x 的亲近程度胜过 u 与 v
返回 不开心的朋友的数目 。
"""


# O（n^3)，可以先记录每个i的朋友对应的亲近度，双O(n^2)，空间换时间
class Solution(object):
    def unhappyFriends(self, n, preferences, pairs):
        """
        :type n: int
        :type preferences: List[List[int]]
        :type pairs: List[List[int]]
        :rtype: int
        """
        pair_one_for_one={}
        # 转化为每个人的映射关系
        for pair in pairs:
            pair_one_for_one[pair[0]]=pair[1]
            pair_one_for_one[pair[1]]=pair[0]
        count=0
        for i in range(n):
            count_before=count  # 只统计一人一次不开心
            for j in preferences[i]:
                # 在i 的朋友中比j亲近度高的已经遍历完或者已经不开心“一次”
                if pair_one_for_one[i] == j or count_before!=count:
                    break
                for k in preferences[j]:
                    # 在j的朋友中找，若先找到i,count+1,若先找到与j配对的，说明其亲进度比i高，退出循环
                    if k==i:
                        count+=1
                        break
                    if k==pair_one_for_one[j]:
                        break
        return count
