n,s=input().split()
cnt=[]
answer=0

for i in range(int(n)):
    a,b=input().split()
    cnt.append(b)
    if a==s:
        answer=b
        break

print(cnt.count(answer)-1)