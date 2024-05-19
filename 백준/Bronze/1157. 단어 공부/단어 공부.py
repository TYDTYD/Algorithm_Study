ch=input().upper()
cnt=[]
a=list((set(ch)))

for i in range(len(a)):
    cnt.append(ch.count(a[i]))

if cnt.count(max(cnt[:]))>=2:
    print("?")
else:
    
    print(a[cnt.index(max(cnt[:]))])