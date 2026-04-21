n,m=map(int,input().split())

sketch=[]
answer=''
index=0

for i in range(n):
    picture=input()
    sketch.append(picture)

for i in range(n):
    for j in range(m):
        if sketch[i][j]!='.' and sketch[i][-j-1]=='.':
            answer+=sketch[i][j]
        elif sketch[i][j]=='.' and sketch[i][-j-1]!='.':
            answer+=sketch[i][-j-1]
        else:
            answer+=sketch[i][j]

for i in range(n):
    for j in range(m):
        print(answer[j+index], end='')
    print()
    index+=m