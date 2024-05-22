import sys
input=sys.stdin.readline

count=[]
index=1
cnt=0

for i in range(int(input())):
    x,y=map(int,input().split())
    z=y-x
    while(z>0):
        cnt=cnt+1
        z=z-index
        if cnt%2==0:
            index=index+1
    count.append(cnt)
    index=1
    cnt=0

for i in range(len(count)):
    print(count[i])