import sys
input=sys.stdin.readline

n=int(input())
palindrome=list(map(int,input().split()))

DP=[] # 저장할 배열

def LCS(n,palindrome): # n은 문자열의 길이
    for i in range(n+1):
        DP.append([0 for _ in range(n+1)])
    for i in range(1,n+1):
        for j in range(1,n+1):
            if palindrome[-i]==palindrome[j-1]: # 두 문자열이 같다면
                DP[i][j]=DP[i-1][j-1]+1 # 이전 결과값에 1 증가하여 갱신
            else:
                DP[i][j]=max(DP[i-1][j],DP[i][j-1]) # 같지않다면 이전 결과값 중 큰 값 갱신
    return DP[n][n] # 최장공통부분순서 길이 반환

print(n-LCS(n,palindrome))