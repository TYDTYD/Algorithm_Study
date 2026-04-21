import sys
import heapq
input=sys.stdin.readline

n,m=map(int,input().split())
result=[]
answer=0

for i in range(n):
    p,l=map(int,input().split())
    mileage=list(map(int,input().split()))
    index=[]
    for j in mileage:
        heapq.heappush(index,-j) # 최댓값 추출을 위해 - 삽입
    if p>=l:
        for j in range(l-1):
            heapq.heappop(index) # 수강인원 들을 수 있는 바로 직전 인원까지 최댓값 빼기
        result.append(-heapq.heappop(index)) # 마지노선 수강인원의 마일리지 추출
    else:
        result.append(1) # 수강인원이 빈다면 1 마일리지

heapq.heapify(result)

for i in range(n):
    answer=i
    m-=heapq.heappop(result) # 현재 갖고 있는 마일리지에서 수강 과목 마일리지 빼기
    if m<0:
        break
    if len(result)==0:
        answer+=1
        break

print(answer)