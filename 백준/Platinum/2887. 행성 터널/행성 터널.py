import sys
input=sys.stdin.readline

def find_parent(parent,x):
    if parent[x]!=x:
        parent[x]=find_parent(parent,parent[x])
    return parent[x]

def union_parent(parent,a,b):
    a=find_parent(parent,a)
    b=find_parent(parent,b)
    if a<b:
        parent[b]=a
    else:
        parent[a]=b

v=int(input())
parent=[0]*(v+1)
edges=[]
xsort=[]
ysort=[]
zsort=[]
result=0

for i in range(1,v+1):
    parent[i]=i

for i in range(1,v+1):
    x,y,z=map(int,input().split())
    xsort.append((x,y,z,i))
    ysort.append((x,y,z,i))
    zsort.append((x,y,z,i))

xsort.sort(key=lambda x:x[0])
ysort.sort(key=lambda x:x[1])
zsort.sort(key=lambda x:x[2])

for i in range(v):
    if i==0:
        edges.append((abs(xsort[i][0]-xsort[i+1][0]),xsort[i][3],xsort[i+1][3]))
        edges.append((abs(ysort[i][1]-ysort[i+1][1]),ysort[i][3],ysort[i+1][3]))
        edges.append((abs(zsort[i][2]-zsort[i+1][2]),zsort[i][3],zsort[i+1][3]))
    elif i==v-1:
        edges.append((abs(xsort[i][0]-xsort[i-1][0]),xsort[i][3],xsort[i-1][3]))     
        edges.append((abs(ysort[i][1]-ysort[i-1][1]),ysort[i][3],ysort[i-1][3]))
        edges.append((abs(zsort[i][2]-zsort[i-1][2]),zsort[i][3],zsort[i-1][3]))
    else:
        edges.append((abs(xsort[i][0]-xsort[i+1][0]),xsort[i][3],xsort[i+1][3]))
        edges.append((abs(xsort[i][0]-xsort[i-1][0]),xsort[i][3],xsort[i-1][3]))
        edges.append((abs(ysort[i][1]-ysort[i+1][1]),ysort[i][3],ysort[i+1][3]))
        edges.append((abs(ysort[i][1]-ysort[i-1][1]),ysort[i][3],ysort[i-1][3]))
        edges.append((abs(zsort[i][2]-zsort[i+1][2]),zsort[i][3],zsort[i+1][3]))
        edges.append((abs(zsort[i][2]-zsort[i-1][2]),zsort[i][3],zsort[i-1][3]))

edges.sort()

for edge in edges:
    cost,a,b=edge
    if find_parent(parent,a)!=find_parent(parent,b):
        union_parent(parent,a,b)
        result+=cost

print(result)