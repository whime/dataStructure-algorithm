"""
输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点
（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
"""


# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# 递归解法
# class Solution:
#     def TreeDepth(self, pRoot):
#         # write code here
#         if pRoot is None:return 0
#         leftDepth=self.TreeDepth(pRoot.left)
#         rightDepth=self.TreeDepth(pRoot.right)
#         return max(leftDepth,rightDepth)+1
# 层次遍历
class Solution:
    def TreeDepth(self, pRoot):
        if pRoot is None: return 0
        nodeList = [pRoot]
        depth = 0
        while nodeList:
            # 每遍历完一层节点就深度加一
            depth += 1
            size = len(nodeList)
            for i in range(0, size):
                node = nodeList[0]
                if node.left:
                    nodeList.append(node.left)
                if node.right:
                    nodeList.append(node.right)
                nodeList.pop(0)
        return depth
