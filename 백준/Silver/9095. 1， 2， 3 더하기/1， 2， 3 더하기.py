def sum123(n):
    array=[1,2,3]
    for i in range(n):
        for j in array:
            sum[i+j]=sum[i+j]+sum[i]
    return sum

T=int(input())

while(T>0):
    T=T-1
    n=int(input())
    sum=[0]*50
    sum[0]=1
    answer=sum123(n)
    print(answer[n])