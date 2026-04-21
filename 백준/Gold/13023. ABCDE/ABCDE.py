import sys
input=sys.stdin.readline
sys.setrecursionlimit(100000)

def dfs(graph,v,visited,count):
    visited[v]=True
    if count==4:
        return True
    for i in graph[v]:
        if not visited[i]:
            if dfs(graph,i,visited,count+1):
                return True
            visited[i]=False # 이걸 추가하면 맞고 제거하면 틀린다?
    return False

n,m=map(int,input().split())
graph=[ [] for _ in range(n)]

for i in range(m):
    a,b=map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)

for i in range(n):
    visited=[False]*n
    if dfs(graph,i,visited,0):
        print(1)
        exit(0)

print(0)