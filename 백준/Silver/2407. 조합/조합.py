n,m=map(int,input().split())

index1=1
index2=1
for i in range(m):
    index1=index1*(n-i)
    index2=index2*(m-i)

print(index1//index2)