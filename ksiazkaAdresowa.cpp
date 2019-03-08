#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMenedzer.logowanieUzytkownika();
    if(uzytkownikMenedzer.zalogowanyUzytkownik()==true)
    {
        kontaktMenedzer = new KontaktMenedzer(NAZWA_PLIKU_Z_KONTAKTAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }
}

void KsiazkaAdresowa::wylogujUzytkownika()
{
    uzytkownikMenedzer.wylogujUzytkownika();
    delete kontaktMenedzer;
    kontaktMenedzer = NULL;
}

void KsiazkaAdresowa::zmianaHaslaUzytkownika()
{
    uzytkownikMenedzer.zmianaHaslaUzytkownika();
}

void KsiazkaAdresowa::dodajKontakt()
{
    if(uzytkownikMenedzer.zalogowanyUzytkownik()==true)
    {
    kontaktMenedzer->dodajKontakt();
    }
}

void KsiazkaAdresowa::wyswietlWszytskieKontakty()
{
    kontaktMenedzer->wyswietlWszystkieKontakty();
}
bool KsiazkaAdresowa::zalogowanyUzytkownik()//NARAZIE TO TU ZOSTAWIAM DLA WYGODY OBSLUGI MENU
{
    return uzytkownikMenedzer.zalogowanyUzytkownik();
}
