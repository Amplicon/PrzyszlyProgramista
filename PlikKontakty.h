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
    const string nazwaPlikuZKontaktami;
    Kontakt pobierzDaneKontaktu(string pojedynczaLiniaDanychKontaktu);
    string przygotujDaneKontaktuDoZapisania(Kontakt kontakt);
    bool czyPlikJestPusty();

public:
    PlikKontakty(string NAZWAPLIKUZKONTAKTAMI):nazwaPlikuZKontaktami(NAZWAPLIKUZKONTAKTAMI){};//lista inicjalizacyjna do const nazwaPlikuZUzytkownikami;
    vector<Kontakt> wczytajKontaktyZPliku();
    void dopiszKontaktDoPliku(Kontakt kontakt);

};

#endif // PLIKKONTAKTY_H
