import sys
input=sys.stdin.readline
sys.setrecursionlimit(100000)

def dfs(x,y):
    if x>=h or x<=-1 or y>=w or y<=-1:
        return False
    if graph[x][y]==0:
        return False
    if graph[x][y]==1:
        graph[x][y]=0
        dfs(x-1,y)
        dfs(x+1,y)
        dfs(x,y-1)
        dfs(x,y+1)
        dfs(x-1,y-1)
        dfs(x-1,y+1)
        dfs(x+1,y+1)
        dfs(x+1,y-1)
        return True
    return False

w,h=map(int,input().split())

while(w!=0 and h!=0):
    result=0
    graph=[ [] for _ in range(h)]
    for i in range(h):
        graph[i]=list(map(int,input().split()))
    for a in range(h):
        for b in range(w):
            if dfs(a,b)==True:
                result=result+1
    print(result)
    w,h=map(int,input().split())