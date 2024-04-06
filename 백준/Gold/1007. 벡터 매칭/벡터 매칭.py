import sys
import math
from itertools import combinations
input=sys.stdin.readline

T=int(input())

while(T>0):
    T-=1
    n=int(input())
    index=[]
    idx=[]
    p=[]
    resultX=0
    resultY=0
    answer=[]

    for i in range(n):
        index.append(i)
        x,y=map(int,input().split())
        p.append((x,y))

    for i in combinations(index,n//2):
        idx.append(i)

    for i in range(len(idx)):
        resultX=0
        resultY=0
        for j in range(n//2):
            resultX+=p[idx[i][j]][0]
            resultY+=p[idx[i][j]][1]
            resultX-=p[idx[-i-1][j]][0]
            resultY-=p[idx[-i-1][j]][1]
        answer.append(math.sqrt((resultX*resultX)+(resultY*resultY)))
    
    print(min(answer))