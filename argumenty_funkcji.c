#include <stdio.h>

//Poniższy kod raczej nie kompiluje się w C++


//Prawdopodobnie to działa po to by zachować zgodność z tym co było przed standardem C
void funkcja(a1,a2)
int a1,a2;
{
    printf("Jestem w funkcji i wartości argumentów to: %d , %d\n",a1,a2);
}

//Tutaj już mamy zmienne globalne
int a3,a4;
void funkcja2(a3,a4)
{
    printf("Jestem w funkcji2 i wartości argumentów to: %d , %d ale tutaj już są to zmienne globalne\n",a3,a4);
}

int funkcja3(a5,a6)
{
    printf("Jestem w funkcji3 i wartości argumentów to: %d , %d\n",a5,a6);
    return 0;
}

int main()
{
    printf("Przed funkcją\n");
    funkcja(1,0);
    //Poniższa linijka nie działa ponieważ nie są to zmienne globalne
    //printf("To nie są globalne zmienne: %d , %d\n",a1,a2);
    printf("Po funkcji\n");

    printf("\nPrzed funkcją2\n");
    funkcja2(99,0x2);
    printf("To są globalne zmienne: %d , %d\n",a3,a4);
    //Dlaczego powyższy printf wyświetli nam 0 , 0?
    //Dlatego ,że mamy tutaj doczynienia z przysłonięciem zmiennych globalnych przez lokalne
    //To znaczy ,że zapis void funkcja2(a3,a4) jest równoważny funkcja2(int a3,int a4)
    printf("Po funkcji2\n");


    printf("\nPrzed funkcją3\n");
    funkcja3(11,0x64);
    printf("Po funkcji3\n");

    return 0;
}

