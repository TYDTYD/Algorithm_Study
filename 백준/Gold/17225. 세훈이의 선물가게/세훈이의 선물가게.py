import sys
import heapq
input=sys.stdin.readline

a,b,n=map(int,input().split())
store=[]
indexB=0
indexR=0
idx=0
count=1
result1=[]
result2=[]

for i in range(n):
    t,c,m=map(str,input().split())
    if c=='B':
        if indexB<=int(t):
            indexB=int(t)
        for j in range(int(m)):
            store.append((indexB,1))
            indexB+=a
    else:
        if indexR<=int(t):
            indexR=int(t)
        for j in range(int(m)):
            store.append((indexR,2))
            indexR+=b

store.sort(key=lambda x:(x[0],x[1]))

for i in store:
    if i[1]==1:
        result1.append(count)
        count+=1
    else:
        result2.append(count)
        count+=1

print(len(result1))
for i in result1:
    print(i,end=' ')
print()
print(len(result2))
for i in result2:
    print(i,end=' ')