import sys
sys.setrecursionlimit(10000)
input=sys.stdin.readline

def dfs(tree,v,visited,idx):
    visited[v]=True
    if len(tree[v])==0:
        idx.append(v)
    for i in tree[v]:
        if visited[i]==True and len(tree[v])==1:
            idx.append(v)
        elif not visited[i]:
            dfs(tree,i,visited,idx)
    return len(idx)

n=int(input())

tree=[[] for i in range(n+1)]
visited=[False]*51
index=[]
answer=[]
graph=[int(ch) for ch in input().split(' ')]

for i in range(n):
    if graph[i]==-1:
        start=i
    else:
        tree[graph[i]].append(i)

remove=int(input())

dfs(tree,remove,visited,index)

if remove==start:
    print(0)
else:
    print(dfs(tree,start,visited,answer))