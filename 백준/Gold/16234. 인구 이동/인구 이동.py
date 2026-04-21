import sys
from collections import deque
input=sys.stdin.readline

def bfs(x,y):
    queue=deque()
    queue.append((x,y))
    visited[x][y]=1
    while queue:
        x,y=queue.popleft()
        for i in range(4):
            nx=x+dx[i]
            ny=y+dy[i]
            if nx<0 or nx>=n or ny<0 or ny>=n:
                continue
            if abs(a[nx][ny]-a[x][y])>=l and abs(a[nx][ny]-a[x][y])<=r:
                if visited[nx][ny]==0:
                    visited[nx][ny]=1
                    plus.append((nx,ny))
                    queue.append((nx,ny))
            else:
                continue

n,l,r=map(int,input().split())
a=[]
plus=[]
count=0
answer=0

dx=[-1,1,0,0]
dy=[0,0,-1,1]

for i in range(n):
    a.append(list(map(int,input().split())))

while(count<n*n):
    visited=[[0]*n for i in range(n)]
    index=0
    count=0
    for i in range(n):
        for j in range(n):
            if visited[i][j]==0:
                bfs(i,j)
                if len(plus)!=0:
                    plus.append((i,j))
                    sum=0
                    for (q,p) in plus:
                        sum=sum+a[q][p]
                    sum=sum//len(plus)
                    for (q,p) in plus:
                        a[q][p]=sum
                    index=1
                    plus=[]
                else:
                    count=count+1
            else:
                count=count+1
    if count==n*n:
        if index==1:
            answer=answer+1
    else:
        answer=answer+1

print(answer)