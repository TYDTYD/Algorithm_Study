import sys
input=sys.stdin.readline

n,s=map(int,input().split())
number=list(map(int,input().split()))
a=0
b=0
length=1
index=[]
sum=number[0]

if max(number)>=s:
    print(1)
else:
    while(b!=n):
        if sum>=s:
            index.append(length)
            sum=sum-number[a]
            a=a+1
            length=length-1
        elif sum<s:
            if b==n-1:
                break
            b=b+1
            sum=sum+number[b]
            length=length+1
    
    if len(index)==0:
        print(0)
    else:
        print(min(index))