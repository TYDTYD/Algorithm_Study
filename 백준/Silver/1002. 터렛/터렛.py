import math

T=int(input())
result=[]

for i in range(T):
    x=[int(ch) for ch in input().split(' ')]
    if math.sqrt((x[0]-x[3])**2+(x[1]-x[4])**2)>x[2]+x[5]:
       result.append(0)
    elif math.sqrt((x[0]-x[3])**2+(x[1]-x[4])**2)==x[2]+x[5]:
        result.append(1)
    elif math.sqrt((x[0]-x[3])**2+(x[1]-x[4])**2)<x[2]+x[5]:
        if x[0]==x[3] and x[1]==x[4] and x[2]==x[5]:
            result.append(-1)
        elif math.sqrt((x[0]-x[3])**2+(x[1]-x[4])**2)+x[2]==x[5] or math.sqrt((x[0]-x[3])**2+(x[1]-x[4])**2)+x[5]==x[2]:
            result.append(1)
        elif math.sqrt((x[0]-x[3])**2+(x[1]-x[4])**2)+x[2]<x[5] or math.sqrt((x[0]-x[3])**2+(x[1]-x[4])**2)+x[5]<x[2]:
            result.append(0)
        else:
            result.append(2)

for j in range(T):
    print(result[j])