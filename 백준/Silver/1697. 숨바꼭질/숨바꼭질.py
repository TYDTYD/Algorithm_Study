import sys
from collections import deque
input=sys.stdin.readline

def bfs(n):
    queue=deque([(n,0)])
    visited=[False]*100001
    visited[n]=True
    while queue:
        n,count=queue.popleft()
        if n==k:
            return count
        graph=[n+1,n-1,2*n] 
        for i in graph:
            if i>=0 and i<100001 and not visited[i]:
                queue.append((i,count+1))
                visited[i]=True

n,k=map(int,input().split())

print(bfs(n))