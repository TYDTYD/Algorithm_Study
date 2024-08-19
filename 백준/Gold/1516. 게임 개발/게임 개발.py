from collections import deque
import sys
input=sys.stdin.readline

n=int(input())
time=[]
result=[0]*(n+1)
indegree=[0]*(n+1)
graph=[[] for _ in range(n+1)]
q=deque()

for i in range(1,n+1):
    build=list(map(int,input().split()))
    time.append(build[0])
    for j in range(1,len(build)-1):
        graph[build[j]].append(i)
        indegree[i]+=1

for i in range(1,n+1):
    if indegree[i]==0:
        q.append(i)

while q:
    index=q.popleft()
    for i in graph[index]:
        indegree[i]-=1
        result[i]=max(result[i],result[index]+time[index-1]) # 진입차수가 여러개일 경우 모든 진입차수가 들어와야 건설이 완료되므로
        if indegree[i]==0:
            q.append(i)

for i in range(1,n+1):
    print(result[i]+time[i-1])