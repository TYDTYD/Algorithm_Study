n=int(input())
a=list(int(x) for x in input().split())
b=sorted(a)
answer=[]

for i in a:
    for j in range(n):
        if i==b[j] and j not in answer:
            answer.append(j)
            break

for i in answer:
    print(i,end=' ')