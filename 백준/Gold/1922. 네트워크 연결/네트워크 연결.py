import sys
import heapq
input=sys.stdin.readline
INF=10**12

v=int(input())
e=int(input())
graph=[[] for _ in range(v)]
Q=[] 
d=[INF]*v 

for i in range(v):
    Q.append(i)

for i in range(e):
    a,b,c=map(int,input().split())
    graph[a-1].append((b-1,c))
    graph[b-1].append((a-1,c))

def Prim(graph,start):
    d[start]=0 
    h=[]
    heapq.heappush(h,(0,start))
    while(len(Q)!=0):
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

print(Prim(graph,0))