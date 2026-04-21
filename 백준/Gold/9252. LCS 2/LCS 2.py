import sys
input=sys.stdin.readline

a=input()
b=input()
C=[]
S=[]
result=[]

def LCS(m,n,c,d):
    answer=[]
    for i in range(m):
        C.append([0 for j in range(n)])
        S.append(['' for k in range(n)])
    for i in range(1,m):
        for j in range(1,n):
            if c[i-1]==d[j-1]:
                C[i][j]=C[i-1][j-1]+1
                S[i][j]=S[i-1][j-1]+c[i-1]
            else:
                C[i][j]=max(C[i-1][j],C[i][j-1])
                if len(S[i-1][j])>len(S[i][j-1]):
                    S[i][j]=S[i-1][j]
                else:
                    S[i][j]=S[i][j-1]
    answer.append(C[m-1][n-1])
    answer.append(S[m-1][n-1])
    return answer

if len(a)<len(b):
    result=LCS(len(a),len(b),a,b)
else:
    result=LCS(len(b),len(a),b,a)

for i in result:
    if i==0:
        print(i)
        break
    else:
        print(i)
