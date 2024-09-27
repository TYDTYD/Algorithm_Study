import sys
from collections import deque
sys.setrecursionlimit(100000)
input=sys.stdin.readline

def dfsF(graph,v,visited,count):
    visited[v]=True
    if depth[count]<k:
        depth[count]+=1
    for i in graph[v]:
        if not visited[i]:
            dfsF(graph,i,visited,count+1)
            
n,k=map(int,input().split())
graph=[ [] for _ in range(n+1)]
depth=[0]*(n+1)
visited=[False]*(n+1)

for i in range(n-1):
    a,b=map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)

dfsF(graph,1,visited,0)

print(sum(depth))