import sys
input=sys.stdin.readline

n,m=map(int,input().split())
index=[]
dict={}

for i in range(n):
    address,password=map(str,input().split())
    dict.update({address:password})

for i in range(m):
    index.append(input())

for i in index:
    print(dict.get(i[:-1]))