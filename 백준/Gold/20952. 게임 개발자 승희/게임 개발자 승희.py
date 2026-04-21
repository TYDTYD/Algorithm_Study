import sys
input=sys.stdin.readline

n,m=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
index=[False]*7
r=[0,1,2,3,4,5,6]
answer=[]
count=[0]*7

for i in range(n):
    count[a[i]%7]+=1

plus = 0
for i in range(m):
    new_r=r.copy()
    new_count=count.copy()
    new_index=index.copy()
    for j in range(7):
        if index[j]==True: 
            continue
        new_r[j]=(r[j]+b[i])%7
        if new_r[j]==0:
            new_count[j]=0
            new_index[j]=True
    if sum(new_count)!=0:
        plus=(plus+b[i])
        r,count,index=new_r,new_count,new_index
    
for i in range(n):
    if index[a[i]%7]==False:
        answer.append((a[i]+plus)%(10**9+7))

print(len(answer))
for i in answer:
    print(i,end=' ')