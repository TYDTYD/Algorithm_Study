import sys
input=sys.stdin.readline

min,max=map(int,input().split())

a=[]
b=[]
index=0
answer=0
count=0

for i in range(min,max+1):
    a.append(i)

for i in range(1500000):
    b.append(i)

for i in range(2,max):
    if b[i]==0:
        continue
    index=i*i
    if index>max:
        break
    while(index<=max):
        if index<=1000000:
            b[index]=0
        if index<=max and index>=min:
            a[index-min]=0
        if min>i*i and count==0:
            count=count+1
            index=(min//(i*i))*(i*i)
        else:
            index=index+i*i
    count=0

for i in range(len(a)):
    if a[i]!=0:
        answer=answer+1

print(answer)