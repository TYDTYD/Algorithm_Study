#include <stdio.h>
#include <string.h>

int main()
{
    char *s=malloc(sizeof(char)*1000000);
    int index1=0;
    int index0=0;
    int i;
    scanf("%s", s);

    for(i=0; i<strlen(s); i++)
    {
        if(s[i]!=s[i+1] && s[i]=='0')
            index0=index0+1;
        else if(s[i]!=s[i+1] && s[i]=='1')
            index1=index1+1;
    }

    if(index0>index1)
        printf("%d",index1);
    else if(index0<index1)
        printf("%d",index0);
    else
        printf("%d",index0);

    free(s);

    return 0;
}
