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
    fstream plikTekstowy;
    const string nazwaPlikuZUzytkownikami;
    bool czyPlikJestPusty();
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);


public:
    PlikUzytkownicy(string NAZWAPLIKUZUZYTKOWNIKAMI):nazwaPlikuZUzytkownikami(NAZWAPLIKUZUZYTKOWNIKAMI){};//lista inicjalizacyjna do const nazwaPlikuZUzytkownikami;
    vector <Uzytkownik> wczytajUzytkownikowZPliku();
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);

};
#endif //PLIKUZYTKOWNICY_H
