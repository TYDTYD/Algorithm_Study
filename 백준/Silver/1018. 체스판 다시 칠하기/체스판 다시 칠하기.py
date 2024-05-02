n,m=map(int,input().split())

array=[]
number=[]
result=0

cp1=['WBWBWBWB','BWBWBWBW','WBWBWBWB','BWBWBWBW','WBWBWBWB','BWBWBWBW','WBWBWBWB','BWBWBWBW']
cp2=['BWBWBWBW','WBWBWBWB','BWBWBWBW','WBWBWBWB','BWBWBWBW','WBWBWBWB','BWBWBWBW','WBWBWBWB']


for i in range(n):
  x=input()
  array.append(x)

for a in range(n-7):
  for b in range(m-7):
    for j in range(8):
      for k in range(8):
        if cp1[j][k]!=array[j+a][k+b]:
          result=result+1
    number.append(result)
    result=0

result=0

for c in range(n-7):
  for d in range(m-7):
    for j in range(8):
      for k in range(8):
        if cp2[j][k]!=array[j+c][k+d]:
          result=result+1
    number.append(result)
    result=0

print(min(number[:]))