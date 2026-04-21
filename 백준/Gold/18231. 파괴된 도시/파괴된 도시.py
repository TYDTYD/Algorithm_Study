import sys
input=sys.stdin.readline

n,m=map(int,input().split())
graph=[[] for i in range(n+1)]
visited=[False]*(n+1)
answer=[]
failure=0
count=0
index=0

for i in range(m):
    a,b=map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)

T=int(input())
city=list(map(int,input().split()))

for i in city:
    index=0
    if len(graph[i])==0:
        visited[i]=True
        count+=1
        answer.append(i)
    else:
        for j in range(len(graph[i])):
            if graph[i][j] not in city:
                break
            elif j==len(graph[i])-1:
                for k in graph[i]:
                    if not visited[k]:
                        index=1
                        visited[k]=True
                if not visited[i]:
                    index=1
                    visited[i]=True
                if index==1:
                    count+=1
                    answer.append(i)
    if visited.count(True)==T:
        break

if visited.count(True)!=T:
    print(-1)
else:
    print(count)
    for i in range(len(answer)):
        print(answer[i],end=' ')