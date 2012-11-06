#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

//float* const zmienna; <-- stały wskaźnik (nie można zmienić adresu wskaźnika)
//const char* zmienna; <-- Wskaźnik na stałą czyli to na co wskazujemy jest stałe

int main()
{
    string str(100,'\0');
    //char tab[100];

    const char* wsk = str.c_str();
    scanf("%s",wsk);//WARNING: writing into constant object (argument 2)

    printf("Znalazlem\n%s\n",wsk);


    const void* wsk2 = str.c_str();
    scanf("%s",(char*)wsk2);//Lub bez rzutowania

    printf("Znalazlem\n%s\n",(char*)wsk2);//lub bez rzutowania


    const char* cos = str.c_str();

    //cos[2] = '3';//error: assignment of read-only location ‘*(cos + 2u)’

    char* cos2 = const_cast<char*>(cos);//Pozbywamy się stałego wskaźnika

    cos2[2] = '#';//Allowed

    cout << "Koniec:" <<str << endl;

    return 0;
}
