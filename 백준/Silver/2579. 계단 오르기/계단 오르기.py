import sys
input=sys.stdin.readline

stair=int(input())
score=[]
result=[]
dp=[[(0,0)] for i in range(stair)]

for i in range(stair):
    score.append((int(input()),1))

for i in range(stair):
    if i==0:
        dp[i]=[score[i]]
    elif i==1:
        dp[i].append((score[i][0]+dp[i-1][0][0],dp[i-1][0][1]+1))
        dp[i].append(score[i])
    else:
        for j in dp[i-1]:
            if j[1]!=2:
                dp[i].append((score[i][0]+j[0],j[1]+1))
        dp[i-2].sort(key=lambda x:-x[0])
        dp[i].append((score[i][0]+dp[i-2][0][0],1))

for i in dp[stair-1]:
    if i[1]!=3:
        result.append(i[0])

print(max(result))