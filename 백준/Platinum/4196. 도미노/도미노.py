import sys
sys.setrecursionlimit(10**6)
input=sys.stdin.readline

def dfs(v,visited,stack):
    visited[v]=True
    for i in graph[v]:
        if not visited[i]:
            dfs(i,visited,stack)
    stack.append(v)

def dfsR(v,visited,stack):
    visited[v]=True
    index[v]=idx
    stack.append(v)
    for i in graphR[v]:
        if not visited[i]:
            dfsR(i,visited,stack)

T=int(input())

for _ in range(T):
    v,e=map(int,input().split())
    graph=[[] for _ in range(v+1)]
    graphR=[[] for _ in range(v+1)]
    visited=[False]*(v+1)
    stack=[]
    idx=0
    index=[-1]*(v+1)

    for i in range(e):
        a,b=map(int,input().split())
        graph[a].append(b)
        graphR[b].append(a)

    for i in range(1,v+1):
        if not visited[i]:
            dfs(i,visited,stack)

    visited=[False]*(v+1)
    count=0
    answer=[]

    while stack:
        scc=[]
        point=stack.pop()
        if not visited[point]:
            idx+=1
            dfsR(point,visited,scc)
            answer.append(sorted(scc))
    scc_indegree=[0]*(idx+1)

    for i in range(1,v+1):
        for j in graph[i]:
            if index[i]!=index[j]:
                scc_indegree[index[j]]+=1
    
    for i in range(1,len(scc_indegree)):
        if scc_indegree[i]==0:
            count+=1

    print(count)