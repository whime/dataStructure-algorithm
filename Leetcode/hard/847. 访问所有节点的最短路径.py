"""
存在一个由 n 个节点组成的无向连通图，图中的节点按从 0 到 n - 1 编号。

给你一个数组 graph 表示这个图。其中，graph[i] 是一个列表，由所有与节点 i 直接相连的节点组成。

返回能够访问所有节点的最短路径的长度。你可以在任一节点开始和停止，也可以多次重访节点，并且可以重用边。
"""


# BFS
class Solution(object):
    def shortestPathLength(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: int
        """
        n = len(graph)
        isAccess = [[0]*(1<<n) for i in range(n)]
        nodes = []
        
        for i in range(n):
            nodes.append((i,1<<i,0))
            isAccess[i][1<<i]=1
        while len(nodes)!=0:
            node = nodes.pop(0)
            if node[1]==((1<<n)-1):
                return node[2]
            for v in graph[node[0]]:
                mask = node[1]|(1<<v)
                if isAccess[v][mask]!=1:
                    isAccess[v][mask]=1
                    nodes.append((v,mask,node[2]+1))