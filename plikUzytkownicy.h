#ifndef PLIKUZYTKOWNICY_H
#define PLIKUZYTKOWNICY_H
#include <iostream>
#include <vector>
#include <fstream>
#include<cstdlib>
#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"
using namespace std;

class PlikUzytkownicy
{
    fstream plikTekstowy;//here
    const string NAZWA_PLIKU_Z_UZYTKOWNIKAMI;

    bool czyPlikJestPusty();
    string przygotujDaneUzytkownikaDoZapisu(Uzytkownik uzytkownik);
    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);


public:
    PlikUzytkownicy(string nazwaPlikuZUzytkownikami):NAZWA_PLIKU_Z_UZYTKOWNIKAMI(nazwaPlikuZUzytkownikami){};//lista inicjalizacyjna do const nazwaPlikuZUzytkownikami;
    vector <Uzytkownik> wczytajUzytkownikowZPliku();
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    void aktualizujPlikUzytkownicy(vector<Uzytkownik> &uzytkownicy);

};
#endif //PLIKUZYTKOWNICY_H
