n,l=map(int,input().split())

h=[int(ch) for ch in input().split(' ')]


h.sort()

for j in range(n):
    if l>=h[j]:
        l=l+1

print(l)