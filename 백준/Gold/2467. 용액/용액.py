import sys
input=sys.stdin.readline

n=int(input())

s=list(map(int,input().split()))
s.sort()

a=0
b=len(s)-1
answer=[]
index=[]
idx=[]

while(a!=b):
    if s[a]+s[b]==0:
        answer=[s[a],s[b]]
        break
    elif s[a]+s[b]>0:
        index.append(abs(s[a]+s[b]))
        idx.append((a,b))
        b=b-1
    elif s[a]+s[b]<0:
        index.append(abs(s[a]+s[b]))
        idx.append((a,b))
        a=a+1

if len(answer)==0:
    answer.extend([s[idx[index.index(min(index))][0]],s[idx[index.index(min(index))][1]]])
    answer.sort()
    for i in range(len(answer)):
        print(answer[i],end=' ')
else:
    answer.sort()
    for i in range(len(answer)):
        print(answer[i],end=' ')