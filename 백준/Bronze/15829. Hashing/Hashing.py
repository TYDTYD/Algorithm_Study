import sys
input=sys.stdin.readline

n=int(input())
s=input()
answer=0

for i in range(n):
    answer=answer+(ord(s[i])-96)*(31**i)

print(answer%1234567891)