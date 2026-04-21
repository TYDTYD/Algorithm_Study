import sys
input=sys.stdin.readline

n=int(input())
xy=[]

for i in range(n):
    x,y=map(int,input().split())
    xy.append((x,y))

resultX=0
resultY=0

for i in range(n):
    if i!=n-1:
        resultX+=xy[i][0]*xy[i+1][1]
        resultY+=xy[i+1][0]*xy[i][1]
    else:
        resultX+=xy[i][0]*xy[0][1]
        resultY+=xy[0][0]*xy[i][1]
                    
area=abs(resultX-resultY)/2

print(round(area*10)/10)