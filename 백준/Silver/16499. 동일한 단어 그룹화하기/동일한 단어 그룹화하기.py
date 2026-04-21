import sys
input=sys.stdin.readline

n=int(input())
result=[[] for i in range(10)]
answer=0

while(n>0):
    s=input()
    n=n-1
    hash=0
    for i in range(len(s)-1):
        hash=hash+7**(ord(s[i])-96)
    result[len(s)-2].append(hash)

for i in range(10):
    answer=answer+len(set(result[i]))

print(answer)