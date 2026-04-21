import sys
import math
input=sys.stdin.readline

n=int(input())
ppi=[]

for i in range(n):
    w,h=map(int,input().split())
    ppi.append(((math.sqrt(w*w+h*h)/77),i+1))

ppi=sorted(ppi,key=lambda x:(-x[0],x[1]))

for i in range(n):
    print(ppi[i][1])