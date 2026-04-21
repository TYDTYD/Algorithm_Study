import sys
input=sys.stdin.readline
INF=10**12

def matrixChain(n):
    for r in range(1,n+1):
        for i in range(1,n+2-r):
            j=i+r-1
            if i==j:
                m[i][j]=0
            else:
                for k in range(i,j):
                    m[i][j]=min(m[i][j],m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j])
    return m[1][n]

n=int(input())
matrix=[]
p=[]

for i in range(n):
    matrix.append(list(map(int,input().split())))

p.append(matrix[0][0])

for i in range(n):
    p.append(matrix[i][1])

m=[[INF]*(n+1) for _ in range(n+1)]

print(matrixChain(n))