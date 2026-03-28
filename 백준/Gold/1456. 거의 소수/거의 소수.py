import math
import sys
input=sys.stdin.readline

count=0
a,b=map(int,input().split())

array=[True for _ in range(int(math.sqrt(b)+1))]

for i in range(2,int(math.sqrt(b)+1)):
    if array[i]==True:
        j=2
        while(int(math.sqrt(b)+1)>i*j):
            array[i*j]=False
            j+=1
        j=2
        while(b>=i**j):
            if a<=i**j:
                count+=1
            j+=1

print(count)