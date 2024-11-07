#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char a[1000];
    char b[1000];
    scanf("%s %s", a, b);
    int sp = 0;
    int sza = strlen(a);
    int szb = strlen(b);
    if (a[0] == '-' && b[0] != '-')
    {
        for (int i = 0; i < sza - 1; i++)
        {
            a[i] = a[i + 1];
        }
        sza--;
        sp = 1;
    }
    else if (a[0] != '-' && b[0] == '-')
    {
        for (int i = 0; i < szb - 1; i++)
        {
            b[i] = b[i + 1];
        }
        szb--;
        sp = 1;
    }
    else if (a[0] == '-' && b[0] == '-')
    {
        for (int i = 0; i < sza - 1; i++)
        {
            a[i] = a[i + 1];
        }
        sza--;
        for (int i = 0; i < szb - 1; i++)
        {
            b[i] = b[i + 1];
        }
        szb--;
        sp = 0;
    }
    int aa[1000] = {0};
    int bb[1000] = {0};
    for (int i = 0; i < sza; i++)
    {
        aa[sza - i] = a[i] - '0';
    }
    for (int i = 0; i < szb; i++)
    {
        bb[szb - i] = b[i] - '0';
    }
    int cc[1100] = {0};
    int szc = sza + szb;
    for (int i = 1; i <= sza; i++)
    {
        for (int j = 1; j <= szb; j++)
        {
            cc[i + j - 1] += aa[i] * bb[j];
            cc[i + j] += cc[i + j - 1] / 10;
            cc[i + j - 1] %= 10;
        }
    }
    while (cc[szc] == 0 && szc > 0)
    {
        szc--;
    }
    /*char ccc[1000];
    for (int i = 0; i < szc; i++)
    {
        ccc[i] = cc[szc - i] + '0';
    }
    ccc[szc] = '\0';
    if (sp == 1)
    {
        printf("-");
    }
    printf("%s\n", ccc);*/
    if (sp == 1)
    {
        printf("-");
    }
    for (int i = szc; i > 0; i--)
    {
        printf("%d", cc[i]);
    }
}