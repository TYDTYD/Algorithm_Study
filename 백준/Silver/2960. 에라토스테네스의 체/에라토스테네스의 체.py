import math
import sys
input=sys.stdin.readline

n,k=map(int,input().split())
count=0
array=[False for _ in range(n+1)]

for i in range(2,n+1):
    if array[i]==False:
        count+=1
        if count==k:
            print(i)
            exit()
        j=2
        while i*j<=n:
            if not array[i*j]:
                array[i*j]=True
                count+=1
            if count==k:
                print(i*j)
                exit()
            j+=1