import sys
import heapq
input=sys.stdin.readline

n=int(input())
c=[]
cr=[]

for i in range(n):
    x,y=map(int,input().split())
    c.append((x,y))

c.sort() # 수업시간 정렬
heapq.heappush(cr,c[0][1]) # 가장 일찍 끝나는 수업시간 집어 넣기

for i in range(1,n):
    if cr[0]>c[i][0]: # 끝나는 수업시간보다 시작시간이 빠를 경우 -> 매칭이 안 될 경우
        heapq.heappush(cr,c[i][1]) # 매칭된 후 수업 삽입
    else: # 끝나는 수업시간보다 시작시간이 늦을 경우 -> 매칭이 될 경우
        heapq.heappop(cr) # 매칭된 전 수업 삭제
        heapq.heappush(cr,c[i][1]) # 매칭 안 된 수업 삽입

print(len(cr)) # 매칭이 서로 안 맞았던 수업의 끝나는 시간만 남게 되므로 -> 강의실 수