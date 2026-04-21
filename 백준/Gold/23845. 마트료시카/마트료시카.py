import sys
input=sys.stdin.readline

n=int(input())
doll=list(map(int,input().split()))
doll.sort()
m=[0]*1000001
answer=0
index=0
count=0

for i in doll:
    m[i]+=1

for i in range(n):
    if m[doll[i]]:
        m[doll[i]]-=1
        index=doll[i]
        count=1
        j=doll[i]+1
        while(True):
            if m[j]:
                index=j
                m[j]-=1
                count+=1
            else:
                answer+=index*count
                break
            j+=1
    
print(answer)