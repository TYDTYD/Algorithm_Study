#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,a,d;
    int x=0;

    scanf("%d %d %d", &n, &a, &d);

    int* p=(int*)malloc(sizeof(int)*n);

    if(n<1 || n>20000 || a<1 || a>10000000 || d<1 || d>10000000)
        return 0;

    for(int i=0; i<n; i++)
    {
        scanf("%d", &p[i]);

        if(p[i]-a==x*d)
        {
            x=x+1;
        }
    }

    printf("%d", x);

    free(p);

    return 0;
}
