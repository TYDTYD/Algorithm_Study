import sys
input=sys.stdin.readline

n=int(input())
dp=[0]*(n+2)
dp[0]=1
tile=[1,2,2]

for i in range(n):
    for j in tile:
        dp[i+j]=dp[i+j]+dp[i]

print(dp[n]%10007)