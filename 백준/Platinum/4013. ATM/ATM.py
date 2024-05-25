import sys
sys.setrecursionlimit(10**6)
from collections import deque
input=sys.stdin.readline

def DFS(v,visited,stack):
    visited[v]=True
    for i in graph[v]:
        if not visited[i]:
            DFS(i,visited,stack)
    stack.append(v)

def DFSR(v,visited,stack):
    visited[v]=True
    stack.append(v)
    index[v]=idx
    for i in graphR[v]:
        if not visited[i]:
            DFSR(i,visited,stack)

n,m=map(int,input().split())
graph=[[] for _ in range(n+1)]
graphR=[[] for _ in range(n+1)]
visited=[False]*(n+1)
stack=[]
index=[-1]*(n+1)
atm=[-1]*(n+1)
checked=[False]*(n+1)
idx=0

for i in range(m):
    a,b=map(int,input().split())
    graph[a].append(b)
    graphR[b].append(a)

for i in range(1,n+1):
    cash=int(input())
    atm[i]=cash

s,p=map(int,input().split())
restaurant=list(map(int,input().split()))

for i in restaurant:
    checked[i]=True

for i in range(1,n+1):
    if not visited[i]:
        DFS(i,visited,stack)

visited=[False]*(n+1)
SCC=[]
scc_sum=[]
idx=0

while stack:
    scc=[]
    scc_plus=0
    point=stack.pop()
    if not visited[point]:
        DFSR(point,visited,scc)
        SCC.append(scc)
        for i in scc:
            scc_plus+=atm[i]
        scc_sum.append(scc_plus)
        idx+=1

start=-1

for i in range(idx):
    if s in SCC[i]:
        start=i
        break

scc_indegree=[0]*idx
scc_graph=[[] for _ in range(idx)]
scc_checked=[False]*idx

for i in range(1,n+1):
    for j in graph[i]:
        if index[i]!=index[j]:
            scc_graph[index[i]].append(index[j])
    if checked[i]:
        scc_checked[index[i]]=True

visited=[False]*(idx)

def dfs(v):
    visited[v]=True
    for i in scc_graph[v]:
        scc_indegree[i]+=1
        if not visited[i]:
            dfs(i)

dfs(start)

q=deque()
DP=[0]*idx
DP[start]=scc_sum[start]

q.append(start)

while q:
    c=q.popleft()
    for i in scc_graph[c]:
        scc_indegree[i]-=1
        DP[i]=max(DP[i],DP[c]+scc_sum[i])
        if scc_indegree[i]==0:
            q.append(i)

answer=0

for i in range(idx):
    if scc_checked[i]:
        answer=max(answer,DP[i])

print(answer)