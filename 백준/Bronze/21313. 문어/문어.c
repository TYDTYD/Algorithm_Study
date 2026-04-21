#include <stdio.h>
int main()
{
    int n;
    int result=1;

    scanf("%d", &n);

    if(n<4 || n>1000)
        return 0;

    for(int i=0; i<n; i++)
    {
        if(n%2!=0 && i==n-1)
        {
            result=result+2;
            printf("%d", result);
        }
        else if(result==1)
        {
            printf("%d ", result);
            result=result+1;
        }
        else if(result==2)
        {
            printf("%d ", result);
            result=result-1;
        }
    }


    return 0;
}