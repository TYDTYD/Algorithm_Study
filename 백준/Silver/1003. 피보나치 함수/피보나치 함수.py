def fib(n):
    if n==0:
        dp=[0]*(n+2)
        dp[0]=1
        dp[1]=0
    elif n==1:
        dp=[0]*(n+2)
        dp[1]=0
        dp[2]=1
    else:
        dp=[0]*(n+1)
        dp[1]=1
        dp[2]=1
        for i in range(3,n+1):
            dp[i]=dp[i-1]+dp[i-2]
    return dp

T=int(input())
answer=[]

while(T>0):
    T=T-1
    n=int(input())
    answer=fib(n)
    print(answer[-2],answer[-1])