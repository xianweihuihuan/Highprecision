#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char a[1000];
    char b[1000];
    scanf("%s %s", a, b);
    int sza = strlen(a);
    int szb = strlen(b);
    int sp = 0;
    if (sza < szb)
    {
        char c[1000];
        strcpy(c, a);
        strcpy(a, b);
        strcpy(b, c);
        int tep = sza;
        sza = szb;
        szb = tep;
        sp = 1;
    }
    else if (sza == szb)
    {
        int aaa = sza;
        while (aaa)
        {
            if (a[aaa] < b[aaa])
            {
                char c[1000];
                strcpy(c, a);
                strcpy(a, b);
                strcpy(b, c);
                int tep = sza;
                sza = szb;
                szb = tep;
                sp = 1;
                break;
            }
            aaa--;
        }
    }
    int aa[1000] = {0};
    int bb[1000] = {0};
    for (int i = 0; i < sza; i++)
    {
        aa[sza - i - 1] = a[i] - '0';
    }
    for (int i = 0; i < szb; i++)
    {
        bb[szb - i - 1] = b[i] - '0';
    }
    int cc[1100];
    int szc = (sza > szb) ? sza : szb;
    for (int i = 0; i < szc; i++)
    {
        if (aa[i] < bb[i])
        {
            aa[i] += 10;
            aa[i + 1]--;
        }
        cc[i] = aa[i] - bb[i];
    }
    while (cc[szc - 1] == 0 && szc - 1 > 0)
    {
        szc--;
    }
    /*char ccc[1000];
    for(int i = 0;i<szc;i++){
        ccc[i] = cc[szc-i-1]+'0';
    }
    ccc[szc] = '\0';
    if(sp==1){
        printf("-");
    }
    printf("%s\n",ccc);*/
    if (sp == 1)
    {
        printf("-");
    }
    for (int i = szc - 1; i >= 0; i--)
    {
        printf("%d", cc[i]);
    }
}