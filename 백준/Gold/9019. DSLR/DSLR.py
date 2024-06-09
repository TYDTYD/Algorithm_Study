import sys
from collections import deque
input=sys.stdin.readline

def dslr(a):
    queue=deque([(a,"")])
    visited=[False]*10000
    visited[a]=True
    while queue:
        a,count=queue.popleft()
        if a==b:
            return answer.append(count)
        graph=[2*a,a-1,(a//100-a//1000*10)*1000+(a//10-a//100*10)*100+(a-a//10*10)*10+a//1000,(a-a//10*10)*1000+(a//1000)*100+(a//100-a//1000*10)*10+(a//10-a//100*10)]
        for i in graph:
            if i==a-1 and i==-1 and not visited[9999]:
                i=9999
                queue.append((i,count+'S'))
                visited[i]=True
            elif i==a-1 and not visited[i]:
                queue.append((i,count+'S'))
                visited[i]=True
            elif i==2*a and i>9999 and not visited[i%10000]:
                i=i%10000
                queue.append((i,count+'D'))
                visited[i]=True
            elif i==2*a and i<10000 and not visited[i]:
                queue.append((i,count+'D'))
                visited[i]=True
            elif i==(a//100-a//1000*10)*1000+(a//10-a//100*10)*100+(a-a//10*10)*10+a//1000 and not visited[i]:
                queue.append((i,count+'L'))
                visited[i]=True
            elif i==(a-a//10*10)*1000+(a//1000)*100+(a//100-a//1000*10)*10+(a//10-a//100*10) and not visited[i]:
                queue.append((i,count+'R'))
                visited[i]=True

T=int(input())
answer=[]

for i in range(T):
    a,b=map(int,input().split())
    dslr(a)

for i in range(len(answer)):
    print(answer[i])