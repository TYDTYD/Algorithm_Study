import sys
input = sys.stdin.readline

def solution(a,b):
    ccw123=ccw(line[a][0],line[a][1],line[a][2],line[a][3],line[b][0],line[b][1])
    ccw124=ccw(line[a][0],line[a][1],line[a][2],line[a][3],line[b][2],line[b][3])
    ccw341=ccw(line[b][0],line[b][1],line[b][2],line[b][3],line[a][0],line[a][1])
    ccw342=ccw(line[b][0],line[b][1],line[b][2],line[b][3],line[a][2],line[a][3])

    if ccw123*ccw124==0 and ccw341*ccw342==0:
        if min(line[a][0],line[a][2])<=max(line[b][0],line[b][2]) and min(line[b][0],line[b][2])<=max(line[a][0],line[a][2]) and min(line[a][1],line[a][3])<=max(line[b][1],line[b][3]) and min(line[b][1],line[b][3])<=max(line[a][1],line[a][3]):
            return 1
    else:
        if ccw123*ccw124<=0 and ccw341*ccw342<=0:
            return 1
    return 0

def ccw(x1,y1,x2,y2,x3,y3):
    return (x2-x1)*(y3-y1)-(y2-y1)*(x3-x1)

def getParent(parent,x):
    if parent[x]==x:
        return x
    else:
        return getParent(parent,parent[x])

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
        return 1
    else:
        return 0

n=int(input())
line=[]
parent=[0]
group=[]
count=[0]*n

for i in range(n):
    line.append(list(map(int,input().split())))
    parent.append(i+1)

for i in range(n):
    for j in range(i):
        if solution(j,i)==1:
            unionParent(parent,j+1,i+1)

for i in range(n):
    group.append(getParent(parent,i+1))
    count[group[-1]-1]+=1

print(len(set(group)))
print(max(count))