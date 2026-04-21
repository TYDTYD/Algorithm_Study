import sys

n,m=map(int, sys.stdin.readline().split())
index1=set([sys.stdin.readline().strip() for _ in range(n)])
index2=set([sys.stdin.readline().strip() for _ in range(m)])

result=sorted(list(index1&index2))

print(len(result))
for i in result:
    print(i)