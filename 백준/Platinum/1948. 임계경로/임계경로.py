from collections import deque
import sys
sys.setrecursionlimit(20000)
input=sys.stdin.readline

n=int(input())
m=int(input())

result=[0]*(n+1)
indegree=[0]*(n+1)
count=0
graph=[[] for _ in range(n+1)]
graph1=[[] for _ in range(n+1)]
visited=[[False for _ in range(n+1)] for _ in range(n+1)]

for i in range(1,m+1):
    p,q,r=map(int,input().split())
    indegree[q]+=1
    graph[p].append((q,r))
    graph1[q].append((p,r))

start,end=map(int,input().split())

q=deque()

for i in range(1,n+1):
    if indegree[i]==0:
        q.append(i)

while q:
    index=q.popleft()
    for i in graph[index]:
        indegree[i[0]]-=1
        result[i[0]]=max(result[i[0]],result[index]+i[1])
        if indegree[i[0]]==0:
            q.append(i[0])

def dfsR(graph,v,visited,res,count):
    for i in graph[v]:
        if not visited[v][i[0]]:
            visited[v][i[0]]=True
            res-=i[1]
            if res==result[i[0]]:
                count+=dfsR(graph,i[0],visited,res,1)
            res+=i[1]
    return count

count=dfsR(graph1,end,visited,result[end],0)

print(result[end])
print(count)