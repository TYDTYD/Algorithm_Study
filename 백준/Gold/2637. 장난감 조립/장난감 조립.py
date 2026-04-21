from collections import deque
import sys
input=sys.stdin.readline

n=int(input())
m=int(input())

indegree=[0]*(n+1)
graph=[[] for _ in range(n+1)]
parts=[[0 for _ in range(n+1)] for _ in range(n+1)]

for i in range(1,m+1):
    x,y,k=map(int,input().split())
    indegree[x]+=1
    graph[y].append((x,k))

q=deque()

for i in range(1,n+1):
    if indegree[i]==0:
        q.append(i)
        parts[i][i]=1

while q:
    index=q.popleft()
    for i in graph[index]:
        indegree[i[0]]-=1
        if indegree[i[0]]==0:
            q.append(i[0])
        for j in range(1,n+1):
            parts[j][i[0]]+=parts[j][index]*i[1]

for i in range(1,n+1):
    if parts[i][n]!=0:
        print(i,parts[i][n])