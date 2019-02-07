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

    int  pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    PlikUzytkownicy plikUzytkownicy;

public:

    Uzytkownik podajDaneNowegoUzytkownika();
    void rejestracjaUzytkownika();


};
#endif //UZYTKOWNIKMENEDZER_H
