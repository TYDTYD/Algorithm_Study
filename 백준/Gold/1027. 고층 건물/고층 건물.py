import sys
input=sys.stdin.readline

n=int(input())
b=list(map(int,input().split()))
m=0
count=0
result=[0]*n

for i in range(len(b)):
    count=0
    for j in range(len(b)):
        if i==j:
            count=0
            continue
        if i<j:
            if count==0:
                m=(b[j]-b[i])/(j-i)
                result[i]=result[i]+1
                count=count+1
            elif m<(b[j]-b[i])/(j-i):
                m=(b[j]-b[i])/(j-i)
                result[i]=result[i]+1
        elif i>j:
            if count==0:
                m=(b[i]-b[i-j-1])/(i-(i-j-1))
                result[i]=result[i]+1
                count=count+1
            elif m>(b[i]-b[i-j-1])/(i-(i-j-1)):
                m=(b[i]-b[i-j-1])/(i-(i-j-1))
                result[i]=result[i]+1 

print(max(result))