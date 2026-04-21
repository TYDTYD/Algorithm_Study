import sys
import heapq
input=sys.stdin.readline
INF=10**12
v=-1
e=-1

def Prim(graph,start):
    d[start]=0
    h=[]
    heapq.heappush(h,(0,start))
    while Q:
        u=deleteMin(h)
        for i in graph[u]:
            if i[0] in Q and i[1]<d[i[0]]:
                d[i[0]]=i[1]
                heapq.heappush(h,(i[1],i[0]))
    return sum(d)

def deleteMin(heap):
    m=heapq.heappop(heap)
    while(m[1] not in Q):
        m=heapq.heappop(heap)
    Q.remove(m[1])
    return m[1]

while(v!=0 and e!=0):
    v,e=map(int,input().split())
    if v==0 and e==0:
        break
    graph=[[] for _ in range(v)]
    Q=[]
    d=[INF]*v
    plus=0

    for i in range(v):
        Q.append(i)

    for i in range(e):
        a,b,c=map(int,input().split())
        graph[a].append((b,c))
        graph[b].append((a,c))
        plus+=c

    print(plus-Prim(graph,graph[0][0][0]))