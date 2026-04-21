import sys
input=sys.stdin.readline

n=int(input())
n=n-4
result=[]
number=[6,2,5,5,4,5,6,3,7,6]
possible=False

if n<12 or n>42:
    print("impossible")
    exit(0)

for i in range(10):
    for j in range(10):
        for k in range(10):
            for l in range(10):
                if int(str(int(str(i)+str(j))+int(str(k)+str(l))))<10:
                    if int(str(i)+str(j))+int(str(k)+str(l))>=100:
                        pass
                    elif n==number[i]+number[j]+number[k]+number[l]+number[int(str(int(str(i)+str(j))+int(str(k)+str(l)))[0])]+6:
                        print(str(i)+str(j)+'+'+str(k)+str(l)+'=0'+str(int(str(i)+str(j))+int(str(k)+str(l))))
                        exit(0)
                elif int(str(i)+str(j))+int(str(k)+str(l))>=100:
                    pass
                elif n==number[i]+number[j]+number[k]+number[l]+number[int(str(int(str(i)+str(j))+int(str(k)+str(l)))[0])]+number[int(str(int(str(i)+str(j))+int(str(k)+str(l)))[1])]:
                    print(str(i)+str(j)+'+'+str(k)+str(l)+'='+str(int(str(i)+str(j))+int(str(k)+str(l))))
                    exit(0)
                    
print("impossible")