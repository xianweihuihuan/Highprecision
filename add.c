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
    szc++;
    for (int i = 0; i < szc; i++)
    {
        cc[i] += aa[i] + bb[i];
        cc[i + 1] = cc[i] / 10;
        cc[i] %= 10;
    }
    while (cc[szc - 1] == 0 && szc - 1 > 0)
    {
        szc--;
    }
    /*char ccc[1000];
    for (int i = 0; i < szc; i++)
    {
        ccc[i] = cc[szc - i - 1] + '0';
    }
    ccc[szc] = '\0';
    printf("%s\n", ccc);*/
    for (int i = szc - 1; i >= 0; i--)
    {
        printf("%d", cc[i]);
    }
}