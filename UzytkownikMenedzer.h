#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H
#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "Uzytkownik.h"
#include "PlikUzytkownicy.h"

using namespace std;

class UzytkownikMenedzer
{
    vector <Uzytkownik> uzytkownicy;
    int idZalogowanegoUzytkownika;
    PlikUzytkownicy plikUzytkownicy;


    int  pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    Uzytkownik podajDaneNowegoUzytkownika();


public:
    UzytkownikMenedzer(string nazwaPlikuZUzytkownikami):plikUzytkownicy(nazwaPlikuZUzytkownikami){
    idZalogowanegoUzytkownika=0;};

    void rejestracjaUzytkownika();
    void wczytajUzytkownikowZPliku();
    int pobierzIdZalogowanegoUzytkownika();
    void logowanieUzytkownika();
    void wylogujUzytkownika();
    void zmianaHaslaUzytkownika();



};
#endif //UZYTKOWNIKMENEDZER_H
