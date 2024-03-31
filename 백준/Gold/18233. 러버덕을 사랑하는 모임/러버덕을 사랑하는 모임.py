from itertools import combinations
import sys
input=sys.stdin.readline

n,p,e=map(int,input().split())
min=[]
max=[]
sum1=sum2=0
count=cnt=0
result=[]
answer=[]
index=index1=index2=0
success=[]

for i in range(n):
    a,b=map(int,input().split())
    min.append((a,i))
    max.append((b,i))

result1=list(combinations(min,p))
result2=list(combinations(max,p))

for i in range(len(result1)):
    sum1=0
    sum2=0
    for j in range(p):
        sum1+=result1[i][j][0]
        sum2+=result2[i][j][0]
    if e>=sum1 and e<=sum2:
        count+=1
        for k in range(p):
            result.append(result1[i][k][1])
        break

if count==0:
    print(-1)
else:
    for i in range(p):
        index+=min[result[i]][0]   
        answer.append(min[result[i]][0])

    index1=e-index
    
    while(index1>0):
        if answer[index2]==max[result[index2]][0]:
            index2+=1
        else:
            index1-=1
            answer[index2]+=1

    for i in range(n):
        if i not in result:
            print(0,end=' ')
        else:
            print(answer[cnt],end=' ')
            cnt=cnt+1