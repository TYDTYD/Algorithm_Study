import sys
import heapq
input=sys.stdin.readline

n=int(input())
array=[]

for i in range(n):
    x=int(input())
    if x==0 and array!=[]:
        print(heapq.heappop(array)[1])
    elif x==0:
        print(0)
    else:
        heapq.heappush(array,(abs(x),x))