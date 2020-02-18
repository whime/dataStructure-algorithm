'''
从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
'''


# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # 返回二维列表[[1,2],[4,5]]
    def Print(self, pRoot):
        # write code here
        if pRoot is None:
            return []
        res = []
        layerRes = []
        layerNode = [pRoot]
        tmp = []
        while len(layerNode) != 0:
            for node in layerNode:
                layerRes.append(node.val)
                if node.left:
                    tmp.append(node.left)
                if node.right:
                    tmp.append(node.right)
            res.append(layerRes)
            layerRes = []
            layerNode = tmp
            tmp = []
        return res

