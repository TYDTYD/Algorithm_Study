n,l=map(int,input().split())
p=[int(ch) for ch in input().split(' ')]
p.sort()
result=0
i=0
j=0

while(i<n):
  if l-1<0:
    i=10000
  elif p[n-1]-p[0]<=l-1:
    result=1
    i=10000
  elif p[i]-p[j]>l-1:
    result=result+1
    if i==n-1:
      result=result+1
    j=i
    i=i+1
  elif p[i]-p[j]==l-1:
    result=result+1
    j=i+1
    i=i+1
  elif p[i]-p[j]<l-1:
    if i==n-1:
      result=result+1
    i=i+1

print(result)