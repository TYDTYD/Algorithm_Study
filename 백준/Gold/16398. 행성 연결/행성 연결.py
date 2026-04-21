import sys
import heapq
input=sys.stdin.readline
INF=10**12

n=int(input())
graph=[[] for _ in range(n)]
Q=[]
d=[INF]*n

for i in range(n):
    Q.append(i)

for i in range(n):
    flow=list(map(int,input().split()))
    for j in range(n):
        if i!=j:
            graph[i].append((j,flow[j]))

def Prim(graph,start):
    d[start]=0
    h=[]
    heapq.heappush(h,(0,start))
    while Q:
        w,u=heapq.heappop(h)
        if u not in Q:
            continue
        Q.remove(u)
        for i in graph[u]:
            if i[0] in Q and i[1]<d[i[0]]:
                d[i[0]]=i[1]
                heapq.heappush(h,(i[1],i[0]))
    return sum(d)

print(Prim(graph,0))