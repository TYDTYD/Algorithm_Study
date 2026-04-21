import sys
input=sys.stdin.readline
INF=int(1e9)

start=1
n,m=map(int,input().split())

distance=[INF]*(n+1)
graph=[]

for i in range(m):
    x,y,z=map(int,input().split())
    graph.append((x,y,z))

def bellmanford(graph,start): 
    distance[start]=0
    for i in range(n):
        for j in range(m):
            if distance[graph[j][1]]>distance[graph[j][0]]+graph[j][2] and distance[graph[j][0]]!=INF:
                distance[graph[j][1]]=distance[graph[j][0]]+graph[j][2]
                if i==n-1: # n을 넘어가면 음의 사이클이므로
                    return True
    return False

cycle=bellmanford(graph,start)

#for i in range(n): #음의 사이클 판단
#    if distance[i]==INF: #시작 정점과 닿지 않은 점들
#        continue
#    for j in graph[i]:
#        for k in graph[j[0]]:
#            if k[0]==i:
#                if distance[i]>distance[j[0]]+k[1]:
#                    detect=True
#                    print(-1)
#                    exit(0)


if cycle==False:
    for i in range(2,n+1):# 시작하는 값 제외
        if distance[i]==INF:
            print(-1)
        else:
            print(distance[i])
else:
    print(-1)