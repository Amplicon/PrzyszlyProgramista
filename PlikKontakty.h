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

    Kontakt pobierzDaneKontaktu(string liniaZDanymiKontaktu);
    string przygotujDaneKontaktuDoZapisania(Kontakt kontakt);
    bool czyPlikJestPusty();
    int pobierzIdUzytkownikaZLinii(string liniaZDanymiKontaktu);
    int pobierzIdKontaktuZLinii(string liniaZDanymiKontaktu);
    void zmienNazwePliku(string nazwaPliku, string nowaNazwaPliku);
    void usunPlik(string nazwaPliku);


public:
    PlikKontakty(string nazwaPlikuZKontaktami):NAZWA_PLIKU_Z_KONTAKTAMI(nazwaPlikuZKontaktami){};//lista inicjalizacyjna do const nazwaPlikuZUzytkownikami;
    vector<Kontakt> wczytajKontaktyUzytkownika(int ID_ZALOGOWANEGO_UZYTKOWNIKA);
    void dopiszKontaktDoPliku(Kontakt kontakt);
    void aktualizujPlikKontakty(Kontakt kontakt);
    void usunKontaktZPliku();


};

#endif // PLIKKONTAKTY_H
