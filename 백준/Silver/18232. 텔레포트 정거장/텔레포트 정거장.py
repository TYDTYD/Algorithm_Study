import sys
from collections import deque
input=sys.stdin.readline

def bfs(s):
    queue=deque([(s,0)])
    visited=[False]*300001
    visited[s]=True
    while queue:
        s,count=queue.popleft()
        if s==e:
            return count
        graph=[s+1,s-1]
        if s<=n:
            if len(teleport[s])>=1:
                for i in teleport[s]:
                    graph.append(i)
        for i in graph:
            if i>=0 and i<300001 and not visited[i]:
                queue.append((i,count+1))
                visited[i]=True

n,m=map(int,input().split())
s,e=map(int,input().split())
teleport=[[] for i in range(n+1)]

for i in range(m):
    a,b=map(int,input().split())
    teleport[a].append(b)
    teleport[b].append(a)

print(bfs(s))