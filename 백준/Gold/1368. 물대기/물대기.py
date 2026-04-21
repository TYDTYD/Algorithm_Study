import sys
import heapq
input=sys.stdin.readline
INF=10**12

n=int(input())
graph=[[] for _ in range(n)]
Q=[] # 최소 신장 트리에 속하지 않은 정점 리스트
d=[INF]*n # 가중치 갱신 리스트 (모두 무한대로 시작)
visited=[False]*n
cost=[]
h=[]

for i in range(n):
    Q.append(i) # 모든 정점 입력

for i in range(n):
    cost.append(int(input()))

for i in range(n):
    field=list(map(int,input().split()))
    for j in range(i+1,n):
        graph[i].append((j,field[j]))
        graph[j].append((i,field[j]))

def Prim(graph,start):
    d[start]=cost[start] # 첫 시작 가중치 우물 파는 비용으로 갱신
    heapq.heappush(h,(cost[start],start)) # 우선순위 큐에 시작점 입력
    while Q:
        w,u=heapq.heappop(h) # 인접 정점 중 가장 가중치가 작은 정점 반환
        if visited[u]:
            continue
        Q.remove(u)
        visited[u]=True
        for i in graph[u]: # 인접 정점 순환하기
            if not visited[i[0]]:
                if cost[i[0]]<d[i[0]] or i[1]<d[i[0]]:
                    minimum=min(cost[i[0]],i[1])
                    d[i[0]]=minimum
                    heapq.heappush(h,(minimum,i[0]))
    return sum(d) # 최소신장트리의 모든 가중치 반환

print(Prim(graph,cost.index(min(cost))))