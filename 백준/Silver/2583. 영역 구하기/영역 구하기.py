import sys
sys.setrecursionlimit(100000)

def area(x,y):
    cnt=0
    if x<=-1 or x>=m or y<=-1 or y>=n:
        return False
    if graph[x][y]==1:
        return False
    if graph[x][y]==0:
        graph[x][y]=1
        cnt=cnt+area(x-1,y)
        cnt=cnt+area(x+1,y)
        cnt=cnt+area(x,y-1)
        cnt=cnt+area(x,y+1)
    return cnt+1


m,n,k=map(int,input().split())
graph=[]
result=0
count=[]

for a in range(m):
  graph.append([0 for b in range(n)])

for i in range(k):
    lx,ly,rx,ry=map(int,input().split())
    for j in range(m):
        for k in range(n):
            if j>=ly and k>=lx and j<ry and k<rx:
                graph[j][k]=1

for i in range(m):
    for j in range(n):
        if graph[i][j]==0:
            count.append(area(i,j))

count.sort()
print(len(count))
for k in range(len(count)):
    print(count[k],end=' ')