#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H
#include <iostream>

#include "UzytkownikMenedzer.h"
#include "KontaktMenedzer.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer;
    KontaktMenedzer *kontaktMenedzer; // wskaznik do obiektu kontakt menedzer
    const string NAZWA_PLIKU_Z_KONTAKTAMI;




public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZKontaktami)
        :uzytkownikMenedzer(nazwaPlikuZUzytkownikami),NAZWA_PLIKU_Z_KONTAKTAMI(nazwaPlikuZKontaktami)
    {
        kontaktMenedzer=NULL;
    };
    ~KsiazkaAdresowa()
    {
        delete kontaktMenedzer;
        kontaktMenedzer=NULL;
    };

    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    bool zalogowanyUzytkownik();//odpytuje menedzera czy uzytkownik jest zalogowany id=0 ==NIE zalogowany
    void wylogujUzytkownika(); //kasuje wskaznik na obiekt kontaktMenedzer
    void dodajKontakt();
    void wyswietlWszytskieKontakty();
    void zmianaHaslaUzytkownika();
    char menuGlowne();
    char menuLogowania();
    void menuWyszukiwania();
    void menuEdycji();
};
#endif//KSIAZKAADRESOWA_H
