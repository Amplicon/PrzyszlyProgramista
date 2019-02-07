#ifndef PLIKUZYTKOWNICY_H
#define PLIKUZYTKOWNICY_H
#include <iostream>
#include <vector>
#include <fstream>
#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"
using namespace std;

class PlikUzytkownicy
{
    string nazwaPlikuZUzytkownikami;
    fstream plikTekstowy;
    bool czyPlikJestPusty();
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);


public:
    PlikUzytkownicy();
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);

};
#endif //PLIKUZYTKOWNICY_H
