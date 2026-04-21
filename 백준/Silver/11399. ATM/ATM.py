import sys
input=sys.stdin.readline

n=int(input())
p=sorted(list(map(int,input().split())))
sum=0
result=0

for i in p:
    sum=sum+i
    result=result+sum

print(result)