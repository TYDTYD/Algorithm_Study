import sys
input=sys.stdin.readline

n=int(input())
score=list(map(int,input().split()))
dp=[0]*n

for i in range(1,n):
    low=10001
    high=-1
    for j in range(i,-1,-1):
        low=min(low,score[j])
        high=max(high,score[j])
        if i!=n-1 or j!=0:
            dp[i]=max(dp[i],high-low+dp[j-1])

print(dp[n-1])