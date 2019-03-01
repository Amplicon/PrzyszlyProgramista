#include <iostream>
#include <windows.h>
#include "KsiazkaAdresowa.h"
using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("BazaUzytkownikow.txt","Kontakty");
    char wybor;

    while(true){
        system("cls");
        cout<<"Menu glowne:\n1 - Rejestracja Uzytkownika\n2 - Logowanie\n3 - Wyjscie"<<endl;
        //cout<<"Status: "<<ksiazkaAdresowa.zalogowanyUzytkownik()<<endl;
        cin>> wybor;
        switch (wybor){

        case '1':
            ksiazkaAdresowa.rejestracjaUzytkownika();
            break;
        case '2':


            ksiazkaAdresowa.logowanieUzytkownika();
            while(ksiazkaAdresowa.zalogowanyUzytkownik()==true)
            {
           ksiazkaAdresowa.dodajKontakt();
           ksiazkaAdresowa.dodajKontakt();
           ksiazkaAdresowa.wyswietlWszytskieKontakty();
            //ksiazkaAdresowa.zmianaHaslaUzytkownika();
            ksiazkaAdresowa.wylogujUzytkownika();
            //cout<<ksiazkaAdresowa.zalogowanyUzytkownik();
            system("pause");
                //zalogujemy sie potem bedzie petla z funkcjami zwiazanymi z programem per se

            }


            break;
        case '3':

            return 0;
        }
    }
}
