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
    int idZalogowanegoUzytkownika;
    vector<Kontakt> kontakty;
    PlikKontakty plikKontakty;

    void wyswietlDaneKontaktu(Kontakt kontakt);
    int pobierzIdNowegoKontaktu();
    Kontakt podajDaneNowegoKontaktu();


public:
    KontaktMenedzer(string nazwaPlikuZKontaktami):plikKontakty(nazwaPlikuZKontaktami)
    {
        idZalogowanegoUzytkownika=0;
    };
    void dodajKontakt();
    void wyswietlWszystkieKontakty();
    void wczytajKontaktyZPliku();
    int pobierzIdZalogowanegoUzytkownika();
    void ustawIdZalogowanegoUzytkownika(int id);

};


#endif // KONTAKTMENEDZER_H
