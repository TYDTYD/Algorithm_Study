#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,k;

    scanf("%d %d",&n, &k);

    if(n<2 || k<2 || n>100000 || k>1000)
        return 0;

    if(k*(k+1)/2>n)
        printf("-1");
    else if((n-(k*(k+1)/2))%k==0)
        printf("%d", k-1);
    else
        printf("%d", k);

    return 0;
}
