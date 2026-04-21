import sys
import heapq
input=sys.stdin.readline

v,e=map(int, input().split())

indegree=[0]*(v+1)
graph=[[] for i in range(v+1)]

for i in range(e):
    a,b=map(int,input().split())
    graph[a].append(b)
    indegree[b]+=1

heap=[]

for i in range(1,v+1):
    if indegree[i]==0:
        heap.append(i)

while heap:
    now=heapq.heappop(heap)
    print(now,end=' ')
    for i in graph[now]:
        indegree[i]-=1
        if indegree[i]==0:
            heapq.heappush(heap,i)