#include <math.h>

int main()
{
    int x1,x2,y1,y2;
    int n,T;
    int k=0;
    int j=0;
    int cx,cy,r;
    int index;

    scanf("%d",&T);

    int *result=malloc(sizeof(int) * T);

    while(T>j)
    {
        scanf("%d %d %d %d", &x1,&y1,&x2,&y2);
        if(x1>1000 || x1<-1000 || x2>1000 || x2<-1000 || y1>1000 || y1<-1000 || y2>1000 || y2<-1000)
            return 0;
        scanf("%d",&n);
        if(n>50 || n<1)
            return 0;
        k=0;
        index=0;
        while(n>k)
        {
            scanf("%d %d %d",&cx,&cy,&r);
            if(cx>1000 || cx<-1000 || cy>1000 || cy<-1000 || r<1 || r>1000)
                return 0;
            if(r>sqrt(pow(abs(x1-cx),2)+pow(abs(y1-cy),2)) && r<sqrt(pow(abs(x2-cx),2)+pow(abs(y2-cy),2)))
                index=index+1;
            if(r>sqrt(pow(abs(x2-cx),2)+pow(abs(y2-cy),2)) && r<sqrt(pow(abs(x1-cx),2)+pow(abs(y1-cy),2)))
                index=index+1;
            k++;
        }
        result[j]=index;
        j++;
    }

    for(int i=0; i<T; i++)
        printf("%d\n", result[i]);

    free(result);

    return 0;
}
