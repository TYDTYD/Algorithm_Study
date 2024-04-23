import sys
input=sys.stdin.readline

T=int(input())

for i in range(T):
    answer=1
    n,m=map(int,input().split())
    n1=1
    m1=1
    for i in range(1,n+1):
        n1=n1*i
    for i in range(n):
        m1=m1*(m-i)

    answer=m1//n1
    print(answer)