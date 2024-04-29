import sys
import math
input=sys.stdin.readline

x,y,d,t=map(int,input().split())
distance=math.sqrt(x**2+y**2)
idx=2

if distance%d==0:
    if distance>t+abs(distance-d):
        while(True):
            if distance>t*idx+abs(distance-d*idx):
                idx+=1
            else:
                idx-=1
                break
        print(t*idx+abs(distance-d*idx))
    else:
        print(distance)
else:
    if distance<d:
        print(min(t*2,t+abs(distance-d),distance))       
    elif distance>t+abs(distance-d):
        while(distance>idx*d):
            if distance>t*idx+abs(distance-d*idx):
                idx+=1
            else:
                idx-=1
                print(t*idx+abs(distance-d*idx))
                exit(0)
        print(min(t*idx,t*(idx-1)+abs(distance-d*(idx-1)),distance))  
    else:
        print(distance)
