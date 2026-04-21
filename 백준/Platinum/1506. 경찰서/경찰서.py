import sys
sys.setrecursionlimit(100000)
input=sys.stdin.readline

def dfs(v,visited,stack):
    visited[v]=True
    for i in graph[v]:
        if not visited[i]:
            stack.append(i)
            dfs(i,visited,stack)
    stack.append(v)

def dfsR(v,visited,stack):
    visited[v]=True
    stack.append(v)
    for i in graphR[v]:
        if not visited[i]:
            dfsR(i,visited,stack)

v=int(input())
graph=[[] for _ in range(v+1)]
graphR=[[] for _ in range(v+1)]
visited=[False]*(v+1)
stack=[]

cost=list(map(int,input().split()))

for i in range(v):
    index=input()
    for j in range(len(index)-1):
        if index[j]=='1':
            graph[i+1].append(j+1)
            graphR[j+1].append(i+1)

for i in range(1,v+1):
    if visited[i] is not True:
        dfs(i,visited,stack)

visited=[False]*(v+1)
answer=[]

while stack:
    scc=[]
    point=stack.pop()
    if visited[point] is not True:
        dfsR(point,visited,scc)
        answer.append(sorted(scc))

result=[]
ans=0
for i in range(len(answer)):
    for j in range(len(answer[i])):
        result.append(cost[answer[i][j]-1])
    ans+=min(result)
    result=[]
    
print(ans)