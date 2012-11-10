#include <iostream>
using namespace std;
int tab2[10];
struct Test{};
struct Test2{char t;};
int main()
{
    int tablica[10];
    char tab[10];

    int* tab3;
    tab3 = new int[10];
    cout << "Rozmiar tablica: " << sizeof(tablica) << " bajtów a to daje wymiar: " << sizeof(tablica)/sizeof(int) << endl;
    cout << "Rozmiar tab: " <<  sizeof(tab) << " bajtów a to daje wymiar: " << sizeof(tab)/sizeof(char) << endl;
    cout << "Rozmiar tab2: " << sizeof(tab2) << " bajtów a to daje wymiar: " << sizeof(tab2)/sizeof(int) << endl;

    //Tak już nie zadziała
    cout << "Rozmiar tab3: " << sizeof(tab3) << " bajtów a to daje wymiar: " << sizeof(tab3)/sizeof(int) << endl;

    //Ciekawe jaki wynik:
    cout << "Rozmiar struktury Test: " << sizeof(Test) << " bajtow" << endl;
     cout << "Rozmiar struktury Test2: " << sizeof(Test2) << " bajtow" << endl;
    return 0;
}
/*
 * sizeof określa rozmiar w czasie kompilacji...
 * */
