from collections import deque
import sys
input=sys.stdin.readline

def topology_sort():
    result=[]
    q=deque()
    for i in range(1,v+1):
        if indegree[i]==0:
            q.append(i)
    while q:
        now=q.popleft()
        result.append(now)
        for i in graph[now]:
            indegree[i]-=1
            if indegree[i]==0:
                q.append(i)
    return result

v,m=map(int, input().split())

indegree=[0]*(v+1)
graph=[[] for i in range(v+1)]
visited=[0]*(v+1)
index=[]
result=False

for i in range(m):
    e=[]
    e=list(map(int,input().split()))
    e.remove(e[0])
    index=index+e
    for j in range(1,len(e)):
        graph[e[j-1]].append(e[j])
        indegree[e[j]]+=1

result=topology_sort()

if indegree.count(0)!=len(indegree):
    print(0)
else:
    for i in result:
        print(i)