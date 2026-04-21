import sys
input=sys.stdin.readline

n=int(input())
box=list(map(int,input().split()))
dp=[1]*n

for i in range(n):
    for j in range(i,n):
        if box[i]<box[j]:
            dp[j]=max(dp[j],dp[i]+1)

print(max(dp))