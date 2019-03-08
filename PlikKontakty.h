#ifndef PLIKKONTAKTY_H
#define PLIKKONTAKTY_H


#include <iostream>
#include <vector>
#include <fstream>
#include<cstdlib>
#include "Kontakt.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikKontakty
{
    fstream plikTekstowy;
    const string NAZWA_PLIKU_Z_KONTAKTAMI;

    Kontakt pobierzDaneKontaktu(string pojedynczaLiniaDanychKontaktu);
    string przygotujDaneKontaktuDoZapisania(Kontakt kontakt);
    bool czyPlikJestPusty();

public:
    PlikKontakty(string nazwaPlikuZKontaktami):NAZWA_PLIKU_Z_KONTAKTAMI(nazwaPlikuZKontaktami){};//lista inicjalizacyjna do const nazwaPlikuZUzytkownikami;
    vector<Kontakt> wczytajKontaktyUzytkownika(int ID_ZALOGOWANEGO_UZYTKOWNIKA);
    void dopiszKontaktDoPliku(Kontakt kontakt);

};

#endif // PLIKKONTAKTY_H
