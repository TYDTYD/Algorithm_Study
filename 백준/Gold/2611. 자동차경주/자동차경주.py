from collections import deque
import sys
input=sys.stdin.readline

n=int(input())
m=int(input())

result=[0]*(n+1)
indegree=[0]*(n+1)
graph=[[] for _ in range(n+1)]
end=[0]*(n+1)
route=[[] for _ in range(n+1)]
answer=[0]*(n+1)

for i in range(1,m+1):
    p,q,r=map(int,input().split())
    if q==1:
        end[p]=r
    else:
        indegree[q]+=1
        graph[p].append((q,r))

q=deque()

for i in range(1,n+1):
    if i==1:
        route[i].append(1)
    if indegree[i]==0:
        q.append(i)

while q:
    index=q.popleft()
    for i in graph[index]:
        indegree[i[0]]-=1
        if result[i[0]]<=result[index]+i[1]:
            route[i[0]]=[]
            route[i[0]].extend(route[index])
            route[i[0]].append(i[0])
            result[i[0]]=result[index]+i[1]
        
        if indegree[i[0]]==0:
            q.append(i[0])

for i in range(1,n+1):
    if end[i]!=0:
        answer[i]=result[i]+end[i]

print(max(answer))
for i in route[answer.index(max(answer))]:
    print(i,end=' ')
print(1)