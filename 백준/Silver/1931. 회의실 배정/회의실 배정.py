import sys
input=sys.stdin.readline

n=int(input())
s=[]

for i in range(n):
    start,end=map(int,input().split())
    s.append((end,start))

def Greedy_Schedule(s,n):
    T=[1]
    last=0
    for i in range(1,n):
        if s[i][1]>=s[last][0]:
            T.append(i)
            last=i
    return len(T)

print(Greedy_Schedule(sorted(s),n))