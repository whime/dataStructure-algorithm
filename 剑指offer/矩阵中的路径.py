'''
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，
每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。
例如
​[a b c e]
[s f c s]
[a d e e]
矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，
路径不能再次进入该格子。
'''
# -*- coding:utf-8 -*-
# DFS + 回溯
class Solution:
    def __init__(self):
        # 用于标记是否访问过对应位置的数据
        self.visited = None

    def hasPath(self, matrix, rows, cols, path):
        # 初始化为0
        self.visited = [0] * len(matrix)
        for i in range(rows):
            for j in range(cols):
                if self.search(matrix, rows, cols, i, j, path, 0):
                    return True
        del self.visited
        return False

    def search(self, matrix, rows, cols, r, c, path, index):# index表示正在匹配字符串的哪个字符
        if index == len(path) - 1 and r < rows and c < cols and self.visited[r * cols + c] == 0:
            # 若到达最后一个字符并且匹配成功，返回True
            return matrix[r * cols + c] == path[index]
        haspath = False
        if r < rows and c < cols and \
                r >= 0 and c >= 0 and self.visited[r * cols + c] == 0 and matrix[r * cols + c] == path[index]:
            self.visited[r * cols + c] = 1
            index += 1
            # 递归查找上下左右四个方向
            haspath = self.search(matrix, rows, cols, r, c + 1, path, index) \
                      or self.search(matrix, rows, cols, r, c - 1, path, index) \
                      or self.search(matrix, rows, cols, r - 1, c, path, index) \
                      or self.search(matrix, rows, cols, r + 1, c, path, index)
            if not haspath:
                index -= 1
                self.visited[r * cols + c] = 0
        return haspath