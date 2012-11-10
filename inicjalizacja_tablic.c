#include <stdio.h>

int tab[15] = { [4] = 5, [7] = 0x01 };

int main()
{
    int i;
    for(i=0;i<15;++i)
    {
        printf("%d liczba = %d\n",i,tab[i]);
    }
    return 0;
}
