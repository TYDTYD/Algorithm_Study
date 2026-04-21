import sys
input=sys.stdin.readline

n,c=map(int,input().split())
count=0
index=False
a=[0]
aa=list(map(int,input().split()))
A=a+aa

def buildHeap(a,n):
    for i in range(n//2,0,-1):
        heapify(a,i,n)

def heapify(a,k,n): # a[k]를 루트로 하는 트리를 힙성질을 만족하도록 수선한다
    global count,index
    left=2*k
    right=2*k+1
    switch=0

    if right<=n: # k가 두 자식을 가지는 경우
        if a[left]<a[right]:
            smaller=left
        else:
            smaller=right
    elif left<=n: # k의 왼쪽 자식만 있는 경우
        smaller=left
    else: # k가 리프노드인 경우
        return 

    if a[smaller]<a[k]:
        switch=a[k]
        a[k]=a[smaller]
        a[smaller]=switch
        count+=1
        if count==c:
            print(a[k],a[smaller])
            index=True
            return
        heapify(a,smaller,n)

def heapSort(a,n): # 힙정렬
    global count,index
    heap=[]
    buildHeap(a,n)
    for i in range(n,1,-1):
        change=a[i]
        a[i]=a[1]
        a[1]=change
        count+=1
        if count==c:
            if a[1]>a[i]:
                print(a[i],a[1])
            else:
                print(a[1],a[i])
            index=True
            return
        heap.append(a[i])
        heapify(a,1,i-1)
    return heap

heapSort(A,len(A)-1)
if index==False:
    print(-1)