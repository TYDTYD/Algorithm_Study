import sys
input=sys.stdin.readline
sys.setrecursionlimit(100000)

def dfs(x,y):
    count=0
    if x>=n or x<=-1 or y>=n or y<=-1:
        return False
    if graph[x][y]=='0':
        return False
    if graph[x][y]=='1':
        graph[x][y]='0'
        count+=dfs(x-1,y)
        count+=dfs(x+1,y)
        count+=dfs(x,y-1)
        count+=dfs(x,y+1)
        return count+1
    return False

n=int(input())
result=0
graph=[ [] for _ in range(n)]
house=[]
for i in range(n):
    graph[i]=list(input())
for a in range(n):
    for b in range(n):
        answer=dfs(a,b)
        if answer>0:
            result=result+1
            house.append(answer)

print(result)
for i in sorted(house):
    print(i)