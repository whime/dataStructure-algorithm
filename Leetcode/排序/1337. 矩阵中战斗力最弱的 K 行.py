"""
给你一个大小为 m * n 的矩阵 mat，矩阵由若干军人和平民组成，分别用 1 和 0 表示。

请你返回矩阵中战斗力最弱的 k 行的索引，按从最弱到最强排序。

如果第 i 行的军人数量少于第 j 行，或者两行军人数量相同但 i 小于 j，那么我们认为第 i 行的战斗力比第 j 行弱。

军人 总是 排在一行中的靠前位置，也就是说 1 总是出现在 0 之前。
"""

# 暴力解法，找出先出现0的行
# class Solution(object):
#     def kWeakestRows(self, mat, k):
#         """
#         :type mat: List[List[int]]
#         :type k: int
#         :rtype: List[int]
#         """
#         m = len(mat)
#         n = len(mat[0])
#         index = []
#         for j in range(n):
#             for i in range(m):
#                 if i not in index and mat[i][j] == 0:
#                     index.append(i)
#                     k -= 1
#                 if k == 0:
#                     break
#             if k == 0:
#                 break
#         if k != 0:
#             for i in range(m):
#                 if i not in index:
#                     index.append(i)
#                     k -= 1
#                 if k == 0:
#                     break
#         return index


# 二分查找+堆排序
class Solution(object):
    def kWeakestRows(self, mat, k):
        """
        :type mat: List[List[int]]
        :type k: int
        :rtype: List[int]
        """
        m,n = len(mat),len(mat[0])
        power = list()
        for i in range(m):
            l,r,pos = 0,n-1,-1
            while l<=r:
                mid = (l+r)//2
                if mat[i][mid] == 0:
                    r = mid-1
                else:
                    l = mid+1
                    pos = mid
            power.append((pos+1,i))

        import heapq
        heapq.heapify(power)
        res = list()
        for i in range(k):
            res.append(heapq.heappop(power)[1])
        return res


if __name__ == '__main__':
    so = Solution()
    print(so.kWeakestRows([[1,1,0,0,0],[1,1,1,1,0],[1,0,0,0,0],[1,1,0,0,0],[1,1,1,1,1]], 3))
