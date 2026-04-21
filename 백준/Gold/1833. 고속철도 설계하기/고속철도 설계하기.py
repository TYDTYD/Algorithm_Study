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

n=int(input())
parent=[0]*(n+1)
edges=[]
result=0 
index=-1
c=0

for i in range(1,n+1):
    parent[i]=i

for i in range(n):
    city=list(map(int,input().split()))
    for j in range(i,n):
        if i!=j:
            edges.append((city[j],i+1,j+1))
            edges.append((city[j],j+1,i+1))
            if city[j]<0: # 가중치가 음수일 경우
                c-=city[j]

edges.sort()
count=0
new=[]

for edge in edges:
    cost,a,b=edge
    if find_parent(parent,a)!=find_parent(parent,b):
        if cost<0:
            union_parent(parent,a,b)
        else:
            union_parent(parent,a,b)
            new.append((a,b))
            count+=1
            result+=cost

print(result+c,count)
for i in range(count):
    print(new[i][0],new[i][1])