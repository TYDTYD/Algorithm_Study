import sys
input=sys.stdin.readline

n=int(input())
s=input()
indexB=0
indexR=0

if s.count('R')==n or s.count('B')==n:
    print(1)
else:
    if s[0]=='R':
        indexR=indexR+1
    else:
        indexB=indexB+1
    for i in range(1,len(s)):
        if s[i]!=s[i-1] and s[i-1]=='B' and s[i]=='R':
            indexR=indexR+1
        elif s[i]!=s[i-1] and s[i-1]=='R' and s[i]=='B':
            indexB=indexB+1
    if indexR>indexB:
        print(1+indexB)
    elif indexB>indexR:
        print(1+indexR)
    else:
        print(1+indexR) #아무거나 집어넣으면 됨