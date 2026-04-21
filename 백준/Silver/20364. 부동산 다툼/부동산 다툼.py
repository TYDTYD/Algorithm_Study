import sys
sys.setrecursionlimit(10000)
input=sys.stdin.readline

def dfs(v,visited):
    if visited[v]==True:
        count.append(v)
        dfs(v//2,visited)
    elif not visited[v] and v==0:
        if len(count)>=1:
            idx.append(count[-1])
        else:
            idx.append(0)
    elif not visited[v]:
        dfs(v//2,visited)

n,q=map(int,input().split())
visited=[False]*(n+1)
idx=[]

for i in range(q):
    count=[]
    x=int(input())
    dfs(x,visited)
    visited[x]=True

for i in range(len(idx)):
    print(idx[i])