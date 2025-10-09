#!/usr/bin/env python3
"""Graph Traversal: BFS and DFS"""
from collections import deque
def bfs(graph,start):
    vis=set([start]); q=deque([start])
    while q:
        v=q.popleft(); print(v,end=" ")
        for n in graph[v]:
            if n not in vis:
                vis.add(n); q.append(n)
def dfs(graph,start,vis=None):
    if vis is None: vis=set()
    vis.add(start); print(start,end=" ")
    for n in graph[start]:
        if n not in vis: dfs(graph,n,vis)
if __name__=="__main__":
    g={1:[2,3],2:[4],3:[4],4:[]}
    print("BFS:",end=" "); bfs(g,1); print("\nDFS:",end=" "); dfs(g,1)
