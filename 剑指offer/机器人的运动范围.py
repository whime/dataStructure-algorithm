'''
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，
右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。
例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，
它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
'''

# -*- coding:utf-8 -*-
class Solution:
    def movingCount(self, threshold, rows, cols):
        # write code here
        visited = [0] * (rows * cols)
        count = self.search(threshold, rows, cols, 0, 0, visited)
        return count

    def calDigitSum(self, num1, num2, k):
        digitSum = 0
        while num1:
            digitSum += num1 % 10
            num1 //= 10
        while num2:
            digitSum += num2 % 10
            num2 //= 10
        if digitSum <=k:
            return True
        return False

    def search(self, threshold, rows, cols, i, j, visited):
        if i < rows and j < cols and i >= 0 and j >= 0 and self.calDigitSum(i, j, threshold) \
                and visited[i * cols + j] == 0:
            visited[i * cols + j] = 1
            count = sum([self.search(threshold, rows, cols, i, j - 1, visited),
                         self.search(threshold, rows, cols, i, j + 1, visited),
                         self.search(threshold, rows, cols, i - 1, j, visited),
                         self.search(threshold, rows, cols, i + 1, j, visited)
                         ]) + 1
            return count
        else:
            return 0
if __name__=='__main__':
    so=Solution()
    print(so.movingCount(5,100,1))