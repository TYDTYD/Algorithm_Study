n=input()

number=[0,0,0,0,0,0,0,0,0,0]
index=0
length=len(n)
result=int(n)

while(index!=length):
    m=int(n[index])
    z=10**(length-(index+1))
    result=result-z*m
    if index==length-1:
        for i in range(10):
            if i==0:
                if int(n)>=100:
                    number[i]=number[i]
            elif m>=i:
                number[i]=number[i]+1
            
    else:
        for i in range(10):
            if i==0:
                number[i]=number[i]+(length-2-index)*(10**(length-3-index))*9
                if m!=0:
                    if index==length-2:
                        number[i]=number[i]+(m*((length-1-index)*(10**(length-2-index))))
                    else:
                        number[i]=number[i]+((m-1)*((length-1-index)*(10**(length-2-index))))
                    if index>=1:
                        number[i]=number[i]+(10**(length-(index+1))+10**(length-(index+2))*(length-(index+1)))        
                else:
                    if index!=length-2:
                        number[i]=number[i]+int(n[index:])+1
                    else:
                        number[i]=number[i]+int(n[index:])+2
            elif m>i:
                number[i]=number[i]+z+(m*(length-index-1)*(z//10))
            elif m==i:
                number[i]=number[i]+(m*(length-index-1)*(z//10))+result+1
            else:
                number[i]=number[i]+(m*(length-index-1)*(z//10))
    index+=1

number[0]=int(number[0])

for i in number:
    print(i,end=' ')