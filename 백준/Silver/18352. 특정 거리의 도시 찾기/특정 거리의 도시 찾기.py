import heapq
import sys
input=sys.stdin.readline
INF=int(1e9)

def dijkstra(start):
    q=[]
    heapq.heappush(q,(0,start))
    distance[start]=0
    while q:
        dist,now=heapq.heappop(q)
        if distance[now]<dist:
            continue
        for i in graph[now]:
            cost=dist+i[1]
            if cost<distance[i[0]]:
                distance[i[0]]=cost
                heapq.heappush(q,(cost,i[0]))

n,m,k,start=map(int,input().split())

graph=[[] for i in range(n+1)]
distance=[INF]*(n+1)
city=[]

for _ in range(m):
    x,y=map(int,input().split())
    graph[x].append((y,1))

dijkstra(start)

for i in range(1,n+1):
    if i==start:
        pass
    elif distance[i]==k:
        city.append(i)

city.sort

if len(city)==0:
    print(-1)
else:
    for i in city:
        print(i)