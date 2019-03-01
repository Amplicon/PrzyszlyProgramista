#ifndef KONTAKT_H
#define KONTAKT_H
#include <iostream>
using namespace std;

class Kontakt
{
    int id;
    string imie;
    string nazwisko;
    string adres;
    string telefon;
    string email;

public:

    void ustawId(int id);
    void ustawImie(string imie);
    void ustawNazwisko(string nazwisko);
    void ustawAdres(string adres);
    void ustawTelefon(string telefon);
    void ustawEmail(string email);

    int pobierzId();
    string pobierzImie();
    string pobierzNazwisko();
    string pobierzAdres();
    string pobierzTelefon();
    string pobierzEmail();

};
#endif//KONTAKT_H
