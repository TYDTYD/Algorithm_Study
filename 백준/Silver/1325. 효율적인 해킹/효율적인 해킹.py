from collections import deque
import sys

input=sys.stdin.readline
n,m=map(int,input().split())
graph=[[] for i in range(n+1)]
ans=[]
solve=[]

def bfs(start):
    q=deque()
    q.append(start)
    result=[0 for i in range(n+1)]
    visit=[0 for i in range(n+1)]
    visit[start]=1
    while q:
        d=q.popleft()
        for i in graph[d]:
            if visit[i]==0:
                visit[i]=1
                result[i]=result[d]+1
                q.append(i)      
    return result

for i in range(m):
    x,y=map(int,input().split())
    graph[y].append(x)

for i in range(1,n+1):
    index=bfs(i)
    answer=0
    for j in range(n+1):
        if index[j]!=0:
            answer=answer+1
    ans.append(answer)

for i in range(n):
    if ans[i]>=max(ans):
        print(i+1,end=' ')