#include <iostream>
#include <windows.h>
#include "KsiazkaAdresowa.h"
using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("BazaUzytkownikow.txt","Kontakty.txt");
    char wybor = ' ';

    while(true)
    {
        wybor = ' ';

        wybor=ksiazkaAdresowa.menuLogowania();

        switch (wybor)
        {

        case '1':

            ksiazkaAdresowa.rejestracjaUzytkownika();
            break;

        case '2':


            ksiazkaAdresowa.logowanieUzytkownika();
            while(ksiazkaAdresowa.zalogowanyUzytkownik()==true)
            {
                char wybor = ' ';

                wybor = ksiazkaAdresowa.menuGlowne();

                switch(wybor)
                {
                case '1':

                    ksiazkaAdresowa.wyswietlWszytskieKontakty();
                    system("pause");
                    break;

                case '2':

                    ksiazkaAdresowa.menuWyszukiwania();
                    break;

                case '3':

                    ksiazkaAdresowa.dodajKontakt();
                    break;

                case '4':

                    ksiazkaAdresowa.menuEdycji();
                    break;

                case '5':

                    ksiazkaAdresowa.zmianaHaslaUzytkownika();
                    break;

                case '6':

                    ksiazkaAdresowa.wylogujUzytkownika();
                    break;

                }
            }


            break;


        case '3':

            return 0;
        }
    }
}
