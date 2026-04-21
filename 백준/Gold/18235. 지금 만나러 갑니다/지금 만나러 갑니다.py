from collections import deque

def bfs5(n,a):
    queue=deque([(a,1)])
    visited5=[[False for i in range(n+1)] for j in range(20)] 
    while queue:
        a,count=queue.popleft()
        if count==20:
            continue
        graph=[a+(2**(count-1)),a-(2**(count-1))] # 오리 위치
        for i in range(len(graph)):
            if i==0:
                if graph[i]<=n and graph[i]>0:
                    visited5[count][graph[i]]=True
                    queue.append((graph[i],count+1))
            elif i==1:
                if graph[i]<=n and graph[i]>0:
                    visited5[count][graph[i]]=True
                    queue.append((graph[i],count+1))
    return visited5

def bfs6(n,b):
    queue=deque([(b,1)])
    visited6=[[False for i in range(n+1)] for j in range(20)] 
    while queue:
        b,count=queue.popleft()
        if count==20:
            continue
        graph=[b+(2**(count-1)),b-(2**(count-1))] # 육리 위치
        for i in range(len(graph)):
            if i==0:
                if graph[i]<=n and graph[i]>0:
                    visited6[count][graph[i]]=True
                    if visited6[count][graph[i]]==True and day1[count][graph[i]]==True:
                        return count
                    queue.append((graph[i],count+1))
            elif i==1:
                if graph[i]<=n and graph[i]>0:
                    visited6[count][graph[i]]=True
                    if visited6[count][graph[i]]==True and day1[count][graph[i]]==True:
                        return count
                    queue.append((graph[i],count+1))      
    return -1

n,a,b=map(int,input().split())

day1=bfs5(n,a)
print(bfs6(n,b))