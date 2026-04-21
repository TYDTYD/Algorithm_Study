import sys
input=sys.stdin.readline

n=int(input())
win=[]
lose=[]
a=0

while(a<=n+1):
    if a<1:
        lose.append(a)
    elif a-1 in lose:
        win.append(a)
    elif a-3 in lose:
        win.append(a)
    elif a-4 in lose:
        win.append(a)
    elif a-1 in win:
        lose.append(a)
    elif a-3 in win:
        lose.append(a)
    elif a-4 in win:
        lose.append(a)
    a=a+1

if n in win:
    print("SK")
else:
    print("CY")