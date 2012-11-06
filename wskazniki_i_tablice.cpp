#include <cstdio>
int main()
{
    // tab[1] = *(tab + 1) = *(1 + tab) = 1[tab]

    int tab[10];
    for(int i=0;i<sizeof(tab)/sizeof(int);++i)
    {
        tab[i] = i;
        printf("%d,",tab[i]);
    }

    tab[1] = 99;
    *(tab + 2) = 100;
    *(3 + tab) = 101;
    3[tab] = 102;

    printf("\nPo zmienie\n\n");
    for(int i=0;i<sizeof(tab)/sizeof(int);++i)
    {
        printf("%d,",tab[i]);
    }
    return 0;
}
