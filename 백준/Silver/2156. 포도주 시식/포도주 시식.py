import sys
input=sys.stdin.readline

n=int(input())
wine=[]
result=[]
dp=[[(0,0)] for i in range(n)]

for i in range(n):
    wine.append((int(input()),1))

for i in range(n):
    if i==0:
        dp[i]=[wine[i]]
    elif i==1:
        dp[i].append((wine[i][0]+dp[i-1][0][0],dp[i-1][0][1]+1))
        dp[i].append(wine[i])
    elif i==2:
        for j in dp[i-1]:
            if j[1]!=2:
                dp[i].append((wine[i][0]+j[0],j[1]+1))
        dp[i-2].sort(key=lambda x:-x[0])
        dp[i].append((wine[i][0]+dp[i-2][0][0],1))
    else:
        for j in dp[i-1]:
            if j[1]!=2:
                dp[i].append((wine[i][0]+j[0],j[1]+1))
        dp[i-2].sort(key=lambda x:-x[0])
        dp[i-3].sort(key=lambda x:-x[0])
        dp[i].append((wine[i][0]+dp[i-2][0][0],1))
        dp[i].append((wine[i][0]+dp[i-3][0][0],1))

for i in dp[n-1]:
    if i[1]!=3:
        result.append(i[0])

for i in dp[n-2]:
    if i[1]!=3:
        result.append(i[0])

print(max(result))