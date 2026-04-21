import sys
import heapq
input=sys.stdin.readline

n,m=map(int,input().split())
charge=list(map(int,input().split()))
machine=[]
for i in range(n):
    heapq.heappush(machine,-charge[i])
index=[0]*m

for i in range(n):
    idx=index.index(min(index))
    index[idx]+=-heapq.heappop(machine)

print(max(index))