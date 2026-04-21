import sys
input=sys.stdin.readline
INF=int(1e9)

def bellmanford(start):
    n=len(graph)
    distance=[INF]*(n+1)
    distance[start]=0

    for i in range(n-2):
        for j in range(1,n):
            for k in graph[j]:
                if distance[k[0]]>distance[j]+k[1]:
                    distance[k[0]]=distance[j]+k[1]

    for i in range(1,n): #음의 사이클 판별
        for j in graph[i]:
            if distance[j[0]]>distance[i]+j[1]:
                return True
    return False

T=int(input())
answer=[]
start=1

while(T>0):
    T=T-1
    n,m,w=map(int,input().split())

    graph=[[] for i in range(n+1)]

    for i in range(m):
        x,y,z=map(int,input().split())
        graph[x].append((y,z))
        graph[y].append((x,z))

    for i in range(w):
        x,y,z=map(int,input().split())
        graph[x].append((y,-z))

    cycle=bellmanford(start)

    if cycle==True:
        answer.append("YES")
    else:
        answer.append("NO")

for i in answer:
    print(i)