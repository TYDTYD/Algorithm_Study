import sys
sys.setrecursionlimit(10**6)
input=sys.stdin.readline

def getParent(parent,x):
    if parent[x]==x:
        return x
    parent[x]=getParent(parent,parent[x])
    return parent[x]

def unionParent(parent,a,b):
    a=getParent(parent,a)
    b=getParent(parent,b)
    if a<b:
        parent[b]=a
    else:
        parent[a]=b

def findParent(parent,a,b):
    a=getParent(parent,a)
    b=getParent(parent,b)
    if a==b:
        return "YES"
    else:
        return "NO"

n,m=map(int,input().split())
parent=[]
for i in range(n+1):
    parent.append(i)

for i in range(m):
    calc,a,b=map(int,input().split())
    if calc==0:
        unionParent(parent,a,b)
    else:
        print(findParent(parent,a,b))