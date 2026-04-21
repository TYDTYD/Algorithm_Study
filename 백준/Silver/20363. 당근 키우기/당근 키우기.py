x,y=map(int,input().split())

if x>y:
    print(x+y+y//10)
else:
    print(x+y+x//10)