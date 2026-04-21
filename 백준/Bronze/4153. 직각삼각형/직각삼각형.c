#include <stdio.h>
int main()
{
    int a=10;
    int b=10;
    int c=10;
    int index=0;
    int x[100];
    int y[100];
    int z[100];

while(a!=0 || b!=0 || c!=0)
    {
        if(a>30000 || b>30000 || c>30000)
            return 0;
        scanf("%d %d %d", &a,&b,&c);
        x[index]=a;
        y[index]=b;
        z[index]=c;
        index=index+1;
    }


    for(int i=0; i<index-1; i++)
        if(z[i]*z[i]==x[i]*x[i]+y[i]*y[i])
            printf("right\n");
        else if(x[i]*x[i]==y[i]*y[i]+z[i]*z[i])
            printf("right\n");
        else if(y[i]*y[i]==x[i]*x[i]+z[i]*z[i])
            printf("right\n");
        else
            printf("wrong\n");

    return 0;
}