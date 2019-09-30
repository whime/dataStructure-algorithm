"""
输入一棵二叉树，判断该二叉树是否是平衡二叉树。
"""

# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def IsBalanced_Solution(self, pRoot):
        # write code here
        treeDepth = self.depth(pRoot)
        if treeDepth == -1:
            return False
        else:
            return True

    def depth(self, root):
        if root is None:
            return 0
        left = self.depth(root.left)
        if left == -1:
            return -1
        right = self.depth(root.right)
        if right == -1:
            return -1
        if abs(left - right) > 1:
            return -1
        else:
            return max(left, right) + 1
