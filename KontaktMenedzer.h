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
    vector<Kontakt> kontakty;
    PlikKontakty plikKontakty;

    Kontakt podajDaneKontaktu();

    void wyswietlDaneKontaktu(Kontakt kontakt);
    int pobierzIdNowegoKontaktu();


public:
        KontaktMenedzer(string nazwaPlikuZKontaktami):plikKontakty(nazwaPlikuZKontaktami){
//    cialo konstruktora
};
void dodajKontakt();
Kontakt podajDaneNowegoKontaktu();
void wyswietlWszystkieKontakty();



};


#endif // KONTAKTMENEDZER_H
