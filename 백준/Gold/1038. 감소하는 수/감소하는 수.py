import sys
input=sys.stdin.readline

n=int(input())
count=[]
index=0
answer=[]
result=0
idx=1
a=-1

if n<10:
    print(n)
elif n>=1023:
    print(-1)
else:
    n=n-9
    for i in range(9):
        count.append(i+1)
        index=index+10
        n=n-count[-1]
        if n<=0:
            print(index+(index//10)+(n-1))
            break
    if n>0:
        for i in range(1,10):
            idx=0
            for k in range(i):
                count.append(0)
                idx=idx+1
            for j in range(9-i):
                count.append(count[-1]+count[10*i-(10-j)])
                idx=idx+1
                n=n-count[-1]
                if n<=0:
                    break
            if n<=0:
                break
        answer.append(idx)
        t=(len(count)//10)-1
        n=n+count[-1]
        while(t>=0):
            a=a+1
            if n-count[9*t+a]>0:
                n=n-count[9*t+a]
            elif n-count[9*t+a]<0:
                answer.append(a+1)
                a=-1
                t=t-1
                if t==-1:
                    answer.append(n-1)
            elif n-count[9*t+a]==0:
                while(t>=-1):
                    answer.append(a+1)
                    a=a-1
                    t=t-1

        p=len(answer)
        for m in range(len(answer)):
            result=result+(10**m)*answer[p-1-m]

        print(result)