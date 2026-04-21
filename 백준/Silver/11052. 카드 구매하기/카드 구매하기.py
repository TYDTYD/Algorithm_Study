import sys
input=sys.stdin.readline

n=int(input())
p=list(map(int,input().split()))
dp=[0]+p

for i in range(n+1):
    for j in range(1,i):
        dp[i]=max(dp[i],dp[i-j]+p[j-1])

print(dp[n])