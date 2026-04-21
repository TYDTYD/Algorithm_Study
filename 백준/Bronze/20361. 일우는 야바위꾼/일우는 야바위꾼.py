n,x,k=map(int,input().split())

for i in range(k):
    a,b=map(int,input().split())
    if a==x:
        x=b
    elif b==x:
        x=a

print(x)