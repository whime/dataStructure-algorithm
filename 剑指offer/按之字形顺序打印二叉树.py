'''
请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，
第三行按照从左到右的顺序打印，其他行以此类推。
PS:这道题返回数据类型也不说明白，只能靠一边调试一边猜？
'''


# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def Print(self, pRoot):
        # write code here
        if pRoot is None:
            return []
        res = [[pRoot.val]]
        nodeList = []
        tmpList = []
        tmpres = []
        layer = 1
        nodeList.append(pRoot)
        while len(nodeList) != 0:

            if layer % 2 == 0:
                layer += 1
                for node in nodeList[::-1]:
                    if node.left is not None:
                        tmpList.append(node.left)
                        tmpres.append(node.left.val)
                    if node.right is not None:
                        tmpList.append(node.right)
                        tmpres.append(node.right.val)
            else:
                layer += 1
                for node in nodeList[::-1]:
                    if node.right is not None:
                        tmpList.append(node.right)
                        tmpres.append(node.right.val)
                    if node.left is not None:
                        tmpList.append(node.left)
                        tmpres.append(node.left.val)
            nodeList = tmpList
            tmpList = []
            res.append(tmpres)
            tmpres = []
        return res[:-1]