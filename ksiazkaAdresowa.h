#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H
#include <iostream>

#include "UzytkownikMenedzer.h"
#include "KontaktMenedzer.h"

using namespace std;

class KsiazkaAdresowa
{
UzytkownikMenedzer uzytkownikMenedzer;
KontaktMenedzer kontaktMenedzer;//


public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZKontaktami):
    uzytkownikMenedzer(nazwaPlikuZUzytkownikami),
    kontaktMenedzer(nazwaPlikuZKontaktami)
    {
        uzytkownikMenedzer.wczytajUzytkownikowZPliku();
        kontaktMenedzer.wczytajKontaktyZPliku();
    };
    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    bool zalogowanyUzytkownik();//odpytuje menedzera czy uzytkownik jest zalogowany id=0 ==NIE zalogowany
    void wylogujUzytkownika(); //zmienia id uzytkownika na 0
    void dodajKontakt();
    void wyswietlWszytskieKontakty();
    void zmianaHaslaUzytkownika();
    void przekazIdUzytkownikaDoMenadzeraKontaktow();
};
#endif//KSIAZKAADRESOWA_H
