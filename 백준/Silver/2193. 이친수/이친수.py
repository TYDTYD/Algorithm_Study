n=int(input())
dp=[1,1]
answer=0
m=0

if n==1 or n==2:
    print(1)
else:
    n=n-2
    while(n>0):
        answer=1+sum(dp[:m+1])
        m=m+1
        dp.append(dp[m]+dp[m-1])
        n=n-1
    print(answer)