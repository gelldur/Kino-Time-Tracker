#include <cstdio>

void fajnaFunkcja(int ile)
{
    static int pole = 2;
    pole += ile;
    printf("pole = %d \n",pole);
}


int main()
{
    fajnaFunkcja(2);
    fajnaFunkcja(2);
    fajnaFunkcja(2);
    return 0;
}
