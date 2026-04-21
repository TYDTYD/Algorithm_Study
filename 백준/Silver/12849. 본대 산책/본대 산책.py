import sys
input=sys.stdin.readline

def walk(dp):
    index=[0]*8
    index[0]=dp[1]+dp[2]
    index[1]=dp[0]+dp[2]+dp[3]
    index[2]=dp[0]+dp[1]+dp[3]+dp[4]
    index[3]=dp[1]+dp[2]+dp[4]+dp[5]
    index[4]=dp[2]+dp[3]+dp[5]+dp[6]
    index[5]=dp[3]+dp[4]+dp[7]
    index[6]=dp[4]+dp[7]
    index[7]=dp[5]+dp[6]

    for i in range(8):
        index[i]=index[i]%1000000007
    return index

dp=[0,1,1,0,0,0,0,0]
d=int(input())

for i in range(d-1):
    dp=walk(dp)

print(dp[0])