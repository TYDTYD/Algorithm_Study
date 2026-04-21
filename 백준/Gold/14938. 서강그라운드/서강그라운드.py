import sys
input=sys.stdin.readline

INF=int(1e9)

n,m,r=map(int,input().split())
t=list(map(int,input().split()))
graph=[[INF]*(n+1) for _ in range(n+1)]
item=[]

for i in range(1,n+1):
    graph[i][i]=0

for i in range(r):
    a,b,c=map(int,input().split())
    graph[a][b]=c
    graph[b][a]=c

for k in range(1,n+1):
    for a in range(1,n+1):
        for b in range(1,n+1):
            graph[a][b]=min(graph[a][b],graph[a][k]+graph[k][b])

for a in range(1,n+1):
    sum=0
    for b in range(1,n+1):
        if graph[a][b]!=INF and graph[a][b]<=m:
            sum+=t[b-1]
    item.append(sum)

print(max(item))