#include <stdio.h>

int main()
{
    int i;
    int a;
    int b;
    int money[1000];
    int T;

        printf("");
        scanf("%d", &T);
        if(T>1000 || T<1)
        {
            goto OUT;
        }

        for(i=0; i<T; i++)
    {
        printf("");
        scanf("%d %d", &a, &b);

           if(a>=22 || a<=0)
            a=0;
            else if(a>=16 && a<=21)
                a=100000;
            else if(a>10)
                a=300000;
            else if(a>6)
                a=500000;
            else if(a>3)
                a=2000000;
            else if(a>1)
                a=3000000;
            else if(a=1)
                a=5000000;

            if(b>=32 || b<=0)
                b=0;
            else if(b>=16 && b<=31)
                b=320000;
            else if(b>7)
                b=640000;
            else if(b>3)
                b=1280000;
            else if(b>1)
                b=2560000;
            else if(b=1)
                b=5120000;

            money[i]=a+b;
        }

    for(i=0; i<T; i++)
    {
        printf("%d\n",money[i]);
    }

    OUT:
    return 0;
}
