#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H
#include <iostream>

#include "UzytkownikMenedzer.h"

using namespace std;

class KsiazkaAdresowa
{
UzytkownikMenedzer uzytkownikMenedzer;



public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami):uzytkownikMenedzer(nazwaPlikuZUzytkownikami){
        uzytkownikMenedzer.wczytajUzytkownikowZPliku();
    };
    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    bool zalogowanyUzytkownik();//odpytuje menedzera czy uzytkownik jest zalogowany id=0 ==NIE zalogowany
    void wylogujUzytkownika(); //zmienia id uzytkownika na 0
    void dodajKontakt();
    void wyswietlWszytskieKontakty();
    void zmianaHaslaUzytkownika();
};
#endif//KSIAZKAADRESOWA_H
