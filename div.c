#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char a[1000];
    int b = 0;
    scanf("%s %d", a, &b);
    int szb = strlen(a);
    int bb[1000];
    int sp = 0;
    if (b == 0)
    {
        printf("error");
        return 1;
    }
    if (b < 0 && a[0] != '-')
    {
        b = -b;
        sp = 1;
    }
    else if (b > 0 && a[0] == '-')
    {
        for (int i = 0; i < szb - 1; i++)
        {
            a[i] = a[i + 1];
        }
        szb--;
        sp = 1;
    }
    else if (b < 0 && a[0] == '-')
    {
        b = -b;
        for (int i = 0; i < szb - 1; i++)
        {
            a[i] = a[i + 1];
        }
        szb--;
    }
    for (int i = 0; i < szb; i++)
    {
        bb[i] = a[i] - '0';
    }
    int cc[1000] = {0};
    int x = 0;
    for (int i = 0; i < szb; i++)
    {
        cc[i] = (x * 10 + bb[i]) / b;
        x = (x * 10 + bb[i]) % b;
    }
    int szc = 0;
    while (cc[szc] == 0 && szc < szb - 1)
    {
        szc++;
    }
    /*char ccc[1000];
    for(int i=0;i<szb-szc;i++){
        ccc[i]=cc[szc+i]+'0';
    }
    ccc[szb-szc]='\0';
    if(sp==1){
        printf("-");
    }
    printf("%s\n",ccc);*/
    if (sp == 1)
    {
        printf("-");
    }
    for (int i = szc; i < szb; i++)
    {
        printf("%d", cc[i]);
    }
}