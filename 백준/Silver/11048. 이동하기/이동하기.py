import sys
input=sys.stdin.readline

def matrixPath(n,m):
    for i in range(1,n+1):
        for j in range(1,m+1):
            candy[i][j]=maze[i-1][j-1]+max(candy[i-1][j],candy[i][j-1],candy[i-1][j-1])
    return candy[n][m]

n,m=map(int,input().split())
maze=[]
candy=[[0 for _ in range(m+1)] for _ in range(n+1)]

for i in range(n):
    maze.append([int(m) for m in input().split()])

print(matrixPath(n,m))