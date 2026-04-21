import sys
import math
input=sys.stdin.readline

n=int(input())
index=[True]*(n+1)
index[0]=False
index[1]=False
max=math.floor(math.sqrt(n)) #내림 함수

for i in range(2, max+1):
    if index[i]: 
        for j in range(i*i,n+1,i):
            index[j] = False

number=[i for i,v in enumerate(index) if v] #숫자 반환
a=0
b=0
count=0

if n==1:
    print(0)
elif n==2:
    print(1)
else:
    while(number[b]<n):
        if sum(number[a:b+1])==n:
            count=count+1
            b=b+1
        elif sum(number[a:b+1])<n:
            b=b+1
        elif sum(number[a:b+1])>n:
            a=a+1
        if number[b]==number[-1]:
            if number[b]==n:
                count=count+1
            break
    print(count)