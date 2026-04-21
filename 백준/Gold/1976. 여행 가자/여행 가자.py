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
        return True
    else:
        return False

n=int(input())
m=int(input())
parent=[]

for i in range(n):
    parent.append(i)

for i in range(n):
    index=list(map(int,input().split()))
    for j in range(n):
        if index[j]==1:
            unionParent(parent,i,j)

plan=list(map(int,input().split()))
for i in range(m-1):
    if findParent(parent,plan[i]-1,plan[i+1]-1) is False:
        print("NO")
        break
    elif i==m-2:
        print("YES")
    else:
        continue