import sys
input=sys.stdin.readline

n=int(input())
RGB=[]
DP=[[0,0,0] for i in range(n)]

for i in range(n):
    RGB.append([int(x) for x in input().split()])

for i in range(n):
    if i==0:
        DP[0]=RGB[0]
    else:
        DP[i][0]=min(RGB[i][0]+DP[i-1][1],RGB[i][0]+DP[i-1][2])
        DP[i][1]=min(RGB[i][1]+DP[i-1][0],RGB[i][1]+DP[i-1][2])
        DP[i][2]=min(RGB[i][2]+DP[i-1][0],RGB[i][2]+DP[i-1][1])

print(min(DP[-1]))