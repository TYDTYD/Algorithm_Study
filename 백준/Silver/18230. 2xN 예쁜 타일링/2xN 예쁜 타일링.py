import sys
input=sys.stdin.readline

n,a,b=map(int,input().split())
x=list(map(int,input().split()))
y=list(map(int,input().split()))
x.sort(reverse=True)
y.sort(reverse=True)
cntx=0
cnty=0
answer=0

if n==1:
    print(x[0])
elif n%2==1:
    answer+=x[cntx]
    cntx+=1
    for i in range(n//2):
        if cntx>=len(x)-1:
            answer+=y[cnty]
            cnty+=1
        elif cnty>=len(y):
            answer=answer+x[cntx]+x[cntx+1]
            cntx+=2
        elif y[cnty]>=x[cntx]+x[cntx+1]:
            answer+=y[cnty]
            cnty+=1
        else:
            answer=answer+x[cntx]+x[cntx+1]
            cntx+=2
    print(answer)
else:
    for i in range(n//2):
        if cntx>=len(x)-1:
            answer+=y[cnty]
            cnty+=1
        elif cnty>=len(y):
            answer=answer+x[cntx]+x[cntx+1]
            cntx+=2
        elif y[cnty]>=x[cntx]+x[cntx+1]:
            answer+=y[cnty]
            cnty+=1
        else:
            answer=answer+x[cntx]+x[cntx+1]
            cntx+=2
    print(answer)