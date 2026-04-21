import sys
input=sys.stdin.readline

n,m,k=map(int,input().split())
result=[0]*n

credit=[[] for i in range(n)]

for i in range(n):
    credit[i]=list(map(int,input().split()))

for i in range(m):
    for j in range(n):
        result[j]+=credit[j][i]
        if result[j]>=k:
            print(j+1,i+1)
            break
    if result[j]>=k:
        break