import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def dfs(node, visit, stack):
    visit[node] = 1
    for now in graph[node]:
        if visit[now] == 0:
            dfs(now, visit, stack)
    stack.append(node)

def reverse_dfs(node, visit, stack):
    visit[node] = 1
    ids[node] = idx
    stack.append(node)
    for now in reverse_graph[node]:
        if visit[now] == 0:
            reverse_dfs(now, visit, stack)

T = int(input())
while T:
    inline = input()
    if inline == '\n':
        continue
    N, M = map(int, inline.split())
    graph = [[] for _ in range(N)]
    reverse_graph = [[] for _ in range(N)]

    for _ in range(M):
        a, b = map(int, input().split())
        graph[a].append(b)
        reverse_graph[b].append(a)
    stack = []
    visit = [0] * N
    for i in range(N):
        if visit[i] == 0:
            dfs(i, visit, stack)
            
    result = [[] for _ in range(N)]
    visit = [0] * N
    idx = -1
    ids = [-1] * N
    
    while stack:
        ssc = []
        node = stack.pop()
        if visit[node] == 0:
            idx += 1
            reverse_dfs(node, visit, ssc)
            result[idx] = ssc
    scc_indegree = [0] * (idx + 1)

    for i in range(N):
        for ed in graph[i]:
            if ids[i] != ids[ed]:
                scc_indegree[ids[ed]] += 1
    cnt = 0
    temp = []
    for i in range(len(scc_indegree)):
        if scc_indegree[i] == 0:
            for r in result[i]:
                temp.append(r)
            cnt += 1
    if cnt == 1:
        for i in sorted(temp):
            print(i)
    else:
        print("Confused")
    print()
    T -= 1