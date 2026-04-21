import sys
import heapq
input=sys.stdin.readline

n=int(input())
number=[]

for i in range(n):
    index=list(map(int,input().split()))
    for j in range(n):
        heapq.heappush(number,index[j])
        if i!=0:
            heapq.heappop(number)

print(heapq.heappop(number))