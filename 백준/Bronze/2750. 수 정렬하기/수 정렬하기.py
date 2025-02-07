import sys
input=sys.stdin.readline

n=int(input())
a=[]

for i in range(n):
    a.append(int(input()))

def selectionSort(a):
    switch=0
    for i in range(len(a)-1,-1,-1):
        largest=0
        for j in range(1,i+1):
            if a[j]>a[largest]:
                largest=j
        switch=a[largest]
        a[largest]=a[i]
        a[i]=switch
    return a

selectionSort(a)

for i in a:
    print(i)