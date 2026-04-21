import sys
from itertools import combinations
input=sys.stdin.readline

n=int(input())
RGB=[]
result=[]
idx=[]
index=[]

for i in range(n):
    r,g,b=map(int,input().split())
    RGB.append((r,g,b))
    idx.append(i+1)

aRGB=list(map(int,input().split()))

for i in range(n):
    if i==0:
        pass
    elif i<7:
        index.append(list(combinations(idx,i+1)))
    else:
        break

for i in range(len(index)):
    for j in index[i]:
        resR=0
        resG=0
        resB=0
        for k in j:
            resR+=RGB[k-1][0]
            resG+=RGB[k-1][1]
            resB+=RGB[k-1][2]
        result.append(abs(aRGB[0]-(resR//len(j)))+abs(aRGB[1]-(resG//len(j)))+abs(aRGB[2]-(resB//len(j))))

print(min(result))