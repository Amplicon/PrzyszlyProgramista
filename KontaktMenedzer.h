#ifndef KONTAKTMENEDZER_H
#define KONTAKTMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include "PlikKontakty.h"
#include "Kontakt.h"
#include "MetodyPomocnicze.h"
using namespace std;

class KontaktMenedzer
{
    PlikKontakty plikKontakty;
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    vector<Kontakt> kontakty;


    void wyswietlDaneKontaktu(Kontakt kontakt);
    int pobierzIdNowegoKontaktu();
    Kontakt podajDaneNowegoKontaktu();


public:
    KontaktMenedzer(string nazwaPlikuZKontaktami, int idZalogowanegoUzytkownika)
    :plikKontakty(nazwaPlikuZKontaktami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
    {
        kontakty = plikKontakty.wczytajKontaktyUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };
    void dodajKontakt();
    void wyswietlWszystkieKontakty();

};


#endif // KONTAKTMENEDZER_H
