#include <iostream>
using namespace std;
//Pola bitowe działają też w C
//W strukturach możemy określić ile bitów będzie miała zmienna


struct Struktura1
{
    int liczba:16;//Zmienna liczba 16 bitowa
    int liczba2:16;//Druga zmienna też 16 bitowa
};
/*Niby ta struktura w pamięci powinna zajmować 8 bajtów przy założeniu
* że int to 4 bajty. Jednak w rzeczywistości będzie zajmowała tylko 4 bajty
* */


struct Struktura2
{
   // int liczba:100; // złe
   int liczba:1;//Wartości od -1 do 0 //Jako signed najstarszy bit jest bitem znaku
};
/*
 * Mimo ,że w strukturze mamy zmienną int 4 bajty ale ustawiliśmy ja na pole bitowe 1
 * to w pamięci będzie ona zajmowała 4 bajty
 * */


struct Struktura3
{
    int liczba:15;
    int liczba2:15;
    int liczba3:2;
    //Powyżej mamy 4 bajty zużyte ,że akurat te 3 inty zmieszczą się w 4 bajtach
};

struct Struktura4
{
    int liczba:15;
    int liczba2:15;
    int liczba3:15;
    //Wyszliśmy pozazakres 4 bajtów więc 8 zarezerwowanych będzie
};

//Czy działa to z innymi typami danych?
struct Struktura5
{
    int liczba:15;
    int liczba2:15;
    char liczba3:2;//Działa
};
class Klasa
{
    int pole:15;//Działają też w klasach w sumie oczywiste różnica między
    //Strukturą a klasą w C++ jest znikoma (domyślne prawa dostępu)
};

int main()
{
    Struktura1 a;
    Struktura1* b;
    b = new Struktura1();
    cout << "Rozmiar zmiennej struktury1: " << sizeof(a) << "bajtow" << endl;
    cout << "Rozmiar struktury1: " << sizeof(Struktura1) << "bajtow" << endl;
    cout << "Rozmiar wskaźnika struktury1: " << sizeof(b) << "bajtow\n\n" << endl;

    Struktura2 c;
    cout << "Rozmiar zmiennej struktury2: " << sizeof(c) << "bajtow" << endl;
    cout << "Rozmiar struktury2: " << sizeof(Struktura2) << "bajtow" << endl;

    c.liczba = 0;
    for(int i=0;i<10;++i)
    {
        cout << "(+1))Wartość liczby w Struktura2: " << c.liczba++ << endl;
    }
    cout << "\n\nRozmiar Struktura3: " << sizeof(Struktura3) << "bajtow" << endl;
    cout << "\n\nRozmiar Struktura4: " << sizeof(Struktura4) << "bajtow" << endl;
    cout << "\n\nRozmiar Struktura5: " << sizeof(Struktura5) << "bajtow" << endl;

    //Nie można stosować sizeof
    //cout << "\n\nRozmiar pola bitowego a.liczba: " << sizeof(a.liczba) << " bajtow" << endl;


    //http://msdn.microsoft.com/en-us/library/ewwyfdbe(v=vs.71).aspx
    //Pola bitowe można ciekawie wykorzystać np.
    /*
     * Nie trzeba wykonywać operacji modulo możemy sami pozwolić się przekręcać licznikowi :)
     * itp.
     * */

    return 0;
}
