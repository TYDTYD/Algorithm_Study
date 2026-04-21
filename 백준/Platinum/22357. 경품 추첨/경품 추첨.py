import math
import sys
input=sys.stdin.readline

k,n=map(int,input().split())
array=[True for _ in range(2501)]
number=[]

for i in range(2,int(math.sqrt(2500))+1):
    if array[i]==True:
        j=2
        while i*j<=2500:
            array[i*j]=False
            j+=1

for i in range(2000,2500):
    if array[i]==True:
        number.append(i)

for i in range(k):
    for j in range(n):
        print(number[i]*(j+1),end=' ')
    print()