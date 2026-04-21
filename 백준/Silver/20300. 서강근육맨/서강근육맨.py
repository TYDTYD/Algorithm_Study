m=[]
n=int(input())
t=[int(x) for x in input().split()]

if n%2!=0:
    m.append(max(t[:]))
    t.remove(max(t[:]))
    n=n-1

for i in range(n//2):
  if n%2==0:
    m.append(int(max(t[:])+int(min(t[:]))))
    t.remove(max(t[:]))
    t.remove(min(t[:]))

print(max(m[:]))