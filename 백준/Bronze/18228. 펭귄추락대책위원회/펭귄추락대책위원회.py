n=int(input())

ice=list(map(int,input().split()))
idx=ice.index(-1)

answer=min(ice[:idx])+min(ice[idx+1:])

print(answer)