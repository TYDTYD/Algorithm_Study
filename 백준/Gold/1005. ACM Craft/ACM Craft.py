from collections import deque
import sys
input=sys.stdin.readline

T=int(input())

for i in range(T):
    v,e=map(int, input().split())
    time=list(map(int,input().split()))

    result=[0]*(v+1)
    indegree=[0]*(v+1)
    graph=[[] for i in range(v+1)]

    for j in range(e):
        a,b=map(int,input().split())
        graph[a].append(b)
        indegree[b]+=1

    want=int(input())
    q=deque()
    for j in range(1,v+1):
        if indegree[j]==0:
            q.append(j)
    while(indegree[want]>0):
        index=q.popleft()
        for k in graph[index]:
            indegree[k]-=1
            result[k]=max(result[k],result[index]+time[index-1])
            if indegree[k]==0:
                q.append(k)
    print(result[want]+time[want-1])