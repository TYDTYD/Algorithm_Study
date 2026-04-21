import sys
sys.setrecursionlimit(1000000)
def dfs(x,y):
  if x<0 or x>=n or y<0 or y>=m:
    return False
  
  if array[x][y]=='1':
    array[x][y]='0'
    dfs(x+1,y)
    dfs(x-1,y)
    dfs(x,y+1)
    dfs(x,y-1)
    dfs(x+1,y+1)
    dfs(x-1,y-1)
    dfs(x+1,y-1)
    dfs(x-1,y+1)
    return True

n,m=map(int,input().split())
array=[]
result=0
index=n

for x in range(n):
  a=input().split()
  array.append(a)


for i in range(index):
  for j in range(m):
    if dfs(i,j)==True:
      result=result+1

print(result)