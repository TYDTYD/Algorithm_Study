n=int(input())
t=list(map(int,input().split()))
g=list(map(int,input().split()))
answer=sum(t) # t 리스트 전체 원소 더하기
g.sort()

for i in range(n):
    answer=answer+i*g[i]

print(answer)