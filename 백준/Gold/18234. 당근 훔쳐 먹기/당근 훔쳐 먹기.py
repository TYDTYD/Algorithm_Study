import sys
input=sys.stdin.readline

n,t=map(int,input().split())
carrot=[]
p=[]

if t==n:
    for i in range(n):
        a,b=map(int,input().split())
        carrot.append(a)
        p.append(b)
else:
    for i in range(n):
        a,b=map(int,input().split())
        carrot.append(a+b*(t-n))
        p.append(b)

answer=sum(carrot)
p.sort()

for i in range(n):
    answer=answer+i*p[i]

print(answer)