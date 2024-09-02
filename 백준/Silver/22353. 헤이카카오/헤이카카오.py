import sys
input=sys.stdin.readline

a,d,k=map(int,input().split())
result=0
d=d/100
k=k/100
k1=k
x=d
y=1
index=0
a1=a

while(x<=1):
    k=x*k1
    if index==0:
        result=result+a1*d # 처음 
    else:
        result=result+a1*x*y
    y=y*(1-x)
    x=x+k  
    index=x
    a1=a1+a
    
if x>1:
    result=result+a1*1*y

print(result)