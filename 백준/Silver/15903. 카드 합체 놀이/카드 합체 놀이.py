import sys
import heapq
input=sys.stdin.readline

n,m=map(int,input().split())

card=list(map(int,input().split()))

for i in range(m):
    heapq.heapify(card)
    x=heapq.heappop(card)
    y=heapq.heappop(card)
    heapq.heappush(card,x+y)
    heapq.heappush(card,x+y)

print(sum(card))