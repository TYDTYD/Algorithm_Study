import sys
sys.setrecursionlimit(10**9)
input=sys.stdin.readline

def dfs(graph,v,visited):
    visited[v]=True
    for i in graph[v]:
        if not visited[i]:
            dfs(graph,i,visited)

n,m=map(int,input().split())
count=0
graph=[[] for _ in range(n+1)]
visited=[False]*(n+1)
visited[0]=True

for i in range(m):
    a,b=map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)

for i in range(1,n):
    if visited[i] is False:
        dfs(graph,i,visited)
        count+=1

if visited.count(False)>=1:
    print(count+visited.count(False))
else:
    print(count)