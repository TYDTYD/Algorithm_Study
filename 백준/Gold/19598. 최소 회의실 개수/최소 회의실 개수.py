import sys
import heapq
input=sys.stdin.readline

n=int(input())
c=[]
cr=[]

for i in range(n):
    x,y=map(int,input().split())
    c.append((x,y))

c.sort() 
heapq.heappush(cr,c[0][1])

for i in range(1,n):
    if cr[0]>c[i][0]: 
        heapq.heappush(cr,c[i][1]) 
    else: 
        heapq.heappop(cr) 
        heapq.heappush(cr,c[i][1])

print(len(cr))