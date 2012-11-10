#include <stdio.h>
//Wiki ==> http://en.wikipedia.org/wiki/XOR_swap_algorithm
void xorSwap (int *a, int *b)
{
    //Trzeba sprawdzić czy adresy są różne
    if (a != b)
    {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
}

void addSwap (int *a, int *b)
{
    if (a != b)
    {
        *a = *a + *b;
        *b = *a - *b;
        *a = *a - *b;
    }
}

int main()
{
    int a=2,b=3;

    printf("a:%d  b:%d\n",a,b);
    xorSwap(&a,&b);
    printf("Po swapie: a:%d  b:%d\n",a,b);

    //A teraz swap na liczbach bez funkcji
    a ^= b;
    b ^= a;
    a ^= b;

    printf("Po swapie2: a:%d  b:%d\n\n",a,b);

    int c=0x01,d=-2;

    printf("c:%d  d:%d\n",c,d);
    addSwap(&c,&d);
    printf("Po swapie: c:%d  d:%d\n",c,d);

    //A teraz swap na liczbach bez funkcji
    c = c + d;
    d = c - d;
    c = c - d;

    printf("Po swapie2: c:%d  d:%d\n",c,d);

    return 0;
}
