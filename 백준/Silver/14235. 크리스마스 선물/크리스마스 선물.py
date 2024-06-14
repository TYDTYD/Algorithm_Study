import sys
import heapq
input=sys.stdin.readline

n=int(input())
gift=[]

for i in range(n):
    gifts=list(map(int,input().split()))
    if gifts[0]==0:
        if len(gift)==0:
            print(-1)
        else:
            print(-(heapq.heappop(gift)))
    else:
        for i in range(gifts[0]):
            heapq.heappush(gift,-gifts[i+1])