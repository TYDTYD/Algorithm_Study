import sys
import math
input = sys.stdin.readline

def minInit(a, tree, node, start, end):
    if start == end:
        tree[node] = a[start]
    else:
        minInit(a, tree, node*2, start, (start+end)//2)
        minInit(a, tree, node*2+1, (start+end)//2+1, end)
        tree[node] = min(tree[node*2], tree[node*2+1])
        
def minQuery(tree, node, start, end, left, right):
    if left > end or right < start:
        return -1
    if left <= start and end <= right:
        return tree[node]
    lmin = minQuery(tree, node*2, start, (start+end)//2, left, right)
    rmin = minQuery(tree, node*2+1, (start+end)//2+1, end, left, right)
    if lmin==-1:
        return rmin
    elif rmin==-1:
        return lmin
    else:
        return min(lmin,rmin)

n, m = map(int, input().split())
a = [int(input()) for _ in range(n)]
h = math.ceil(math.log2(n))
tree_size = 1 << (h+1)
mintree = [0] * tree_size
minInit(a, mintree, 1, 0, n-1)
for _ in range(m):
    t1, t2 = map(int, input().split())
    left, right = t1, t2
    print(minQuery(mintree, 1, 0, n-1, left-1, right-1))