import sys
input=sys.stdin.readline

n,m=map(int,input().split())
graph=[ [] for i in range(n+1)]
dp=[0]*(n+1)

def car(dp):
    index=[0]*(n+1)
    for i in range(1,n+1):
        for j in graph[i]:
            index[i]+=dp[j]
    return index

for i in range(m):
    u,v=map(int,input().split())
    graph[u].append(v)
    graph[v].append(u)
    dp[u]=1
    dp[v]=1

for i in range(7):
    dp=car(dp)

print(sum(dp)%(10**9+7))