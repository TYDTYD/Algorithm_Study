import sys
input=sys.stdin.readline
INF=10**12

n=int(input())
RGB=[]
DP=[[0,0,0] for i in range(n)]
answer=[]

for i in range(n):
    RGB.append([int(x) for x in input().split()])

for i in range(3):
    for j in range(n):
        if j==0:
            for k in range(3):
                DP[0][k]=RGB[0][i]
        elif j==1:
            for k in range(3):
                if k!=i:
                    DP[j][k]=min(RGB[j][k]+DP[j-1][k-1],RGB[j][k]+DP[j-1][k-2])
                else:
                    DP[j][k]=INF
        elif j!=n-1:
            DP[j][0]=min(RGB[j][0]+DP[j-1][1],RGB[j][0]+DP[j-1][2])
            DP[j][1]=min(RGB[j][1]+DP[j-1][0],RGB[j][1]+DP[j-1][2])
            DP[j][2]=min(RGB[j][2]+DP[j-1][0],RGB[j][2]+DP[j-1][1])
        else:
            for k in range(3):
                if k!=i:
                    DP[j][k]=min(RGB[j][k]+DP[j-1][k-1],RGB[j][k]+DP[j-1][k-2])
                else:
                    DP[j][k]=INF
    answer.append(min(DP[-1]))

print(min(answer))