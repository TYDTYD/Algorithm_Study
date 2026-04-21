import sys
input=sys.stdin.readline

INF=int(1e9)

v,e=map(int,input().split())

graph=[[INF]*(v+1) for _ in range(v+1)]
result=[]

for a in range(1,v+1):
    for b in range(1,v+1):
        if a==b:
            graph[a][b]=0

for i in range(e):
    a,b,c=map(int,input().split())
    if graph[a][b]==INF or graph[a][b]>c:
        graph[a][b]=c

for k in range(1,v+1):
    for a in range(1,v+1):
        for b in range(1,v+1):
            graph[a][b]=min(graph[a][b],graph[a][k]+graph[k][b])

for a in range(1,v+1):
    for b in range(1,v+1):
        if a!=b:
            result.append(graph[a][b]+graph[b][a])

if min(result)>=INF:
    print(-1)
else:
    print(min(result))