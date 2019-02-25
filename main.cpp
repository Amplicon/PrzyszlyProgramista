#include <iostream>
#include <windows.h>
#include "KsiazkaAdresowa.h"
using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("BazaUzytkownikow.txt");
    char wybor;

    while(true){
        system("cls");
        cout<<"Menu glowne:\n1 - Rejestracja Uzytkownika\n2 - Logowanie\n3 - Wyjscie"<<endl;
        cin>> wybor;
        switch (wybor){

        case '1':
            ksiazkaAdresowa.rejestracjaUzytkownika();
            break;
        case '2':


            ksiazkaAdresowa.logowanieUzytkownika();
            while(ksiazkaAdresowa.zalogowanyUzytkownik()==true)// metoda ksiazki adresowej - nie maina
            {
            cout<<"Hi i am working fine";
            ksiazkaAdresowa.wylogujUzytkownika();
                //zalogujemy sie potem bedzie petla z funkcjami zwiazanymi z programem per se
                //petla ma sprawdzac warunek czy uzytkownik jest zalogowany i tylko wtedy sie wykonywac.
            }


            break;
        case '3':

            return 0;
        }
    }
}
