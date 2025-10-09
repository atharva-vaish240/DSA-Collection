#!/usr/bin/env python3
"""Dijkstra's Shortest Path - O(V^2) simple"""
import sys
def dijkstra(graph,src):
    n=len(graph); dist=[sys.maxsize]*n; visited=[0]*n; dist[src]=0
    for _ in range(n):
        u=min((d for d in range(n) if not visited[d]), key=lambda x:dist[x])
        visited[u]=1
        for v in range(n):
            if graph[u][v] and not visited[v] and dist[u]+graph[u][v]<dist[v]:
                dist[v]=dist[u]+graph[u][v]
    return dist
if __name__=="__main__":
    g=[[0,2,0,1,0],[2,0,3,2,0],[0,3,0,0,1],[1,2,0,0,1],[0,0,1,1,0]]
    print(dijkstra(g,0))
