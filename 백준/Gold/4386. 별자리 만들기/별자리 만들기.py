import sys
import math
input=sys.stdin.readline

def find_parent(parent,x):
    if parent[x]!=x:
        parent[x]=find_parent(parent,parent[x])
    return parent[x]

def union_parent(parent,a,b):
    a=find_parent(parent,a) # a의 루트노드 찾기
    b=find_parent(parent,b) # b의 루트노드 찾기
    if a<b: # a가 더 작을경우
        parent[b]=a # b의 루트노드 = a
    else:
        parent[a]=b # a의 루트노드 = b

v=int(input())
e=(v*(v-1))//2
parent=[0]*(v+1)
edges=[]
result=0
xy=[]
index=0

for i in range(1,v+1):
    parent[i]=i

for i in range(v):
    x,y=map(float,input().split())
    xy.append((x,y))

#if v==1:
#    print(0)
#elif v==2:
#    print(math.sqrt((xy[0][0]-xy[1][0])**2+(xy[0][1]-xy[1][1])**2))
#else:
for i in range(v-1):
    index=i+1
    while(v-index>0):
        edges.append((math.sqrt((xy[i][0]-xy[index][0])**2+(xy[i][1]-xy[index][1])**2),i,index))
        index+=1
edges.sort()

for edge in edges:
    cost,a,b=edge
    if find_parent(parent,a)!=find_parent(parent,b): # 사이클 판단
        union_parent(parent,a,b) # 합쳤을때 루트노드 정하기
        result+=cost

print(result)