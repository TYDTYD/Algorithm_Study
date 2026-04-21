import sys
sys.setrecursionlimit(10000)
input=sys.stdin.readline

def dfs(x,y):
    if x>=n or x<=-1 or y>=m or y<=-1:
        return False
    if graph1[x][y]==index1:
        graph1[x][y]=index2
        dfs(x-1,y)
        dfs(x+1,y)
        dfs(x,y-1)
        dfs(x,y+1)
    return True
    

n,m=map(int,input().split())
graph1=[]
graph2=[]
count=0

for i in range(n):
    graph1.append([int(x) for x in input().split()])

for i in range(n):
    graph2.append([int(x) for x in input().split()])

for i in range(n):
    for j in range(m):
        if graph1[i][j]!=graph2[i][j] and count==0:
            count=count+1
            index1=graph1[i][j]
            index2=graph2[i][j]
            answer=dfs(i,j)


if graph1!=graph2:
    print("NO")
else:
    print("YES")