import math
import sys
input=sys.stdin.readline

count=0
n=int(input())
a=list(map(int,input().split()))

array=[True for i in range(max(a)+1)]

for i in range(2,int(math.sqrt(max(a)))+1):
    if array[i]==True:
        j=2
        while i*j<=max(a):
            array[i*j]=False
            j+=1

for i in a:
    if array[i] and i!=1 and i!=0:
        count+=1

print(count)