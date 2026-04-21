from collections import deque
import sys
input=sys.stdin.readline
   
n,m=map(int, input().split())

answer=[0]*(n+1)
result=[0]*(n+1)
indegree=[0]*(n+1)
graph=[[] for i in range(n+1)]

for i in range(m):
    a,b=map(int,input().split())
    graph[a].append(b)
    indegree[b]+=1

q=deque()

def dp():
    for i in range(1,n+1):
        if indegree[i]==0:
            q.append(i)
            answer[i]=result[i]+1

    while(q):
        index=q[0]
        q.popleft()
        for i in graph[index]:
            indegree[i]-=1
            result[i]=max(result[i],result[index]+1)
            if indegree[i]==0:
                q.append(i)
                answer[i]=result[i]+1

dp()

for i in range(1,n+1):
    print(answer[i],end=' ')