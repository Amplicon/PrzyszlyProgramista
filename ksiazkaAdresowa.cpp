#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

bool KsiazkaAdresowa::zalogowanyUzytkownik()
{
    bool statusUzytkownika=false;

    if( uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika()>0)
    {
        statusUzytkownika=true;
        return statusUzytkownika;
    }
    else if(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika()==0)
    {
        statusUzytkownika=false;
        return statusUzytkownika;
    }
    else
    {
        cout<<"Bledne Id Uzytkownika";
        return statusUzytkownika=false;
    }

}

void KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMenedzer.logowanieUzytkownika();
}

void KsiazkaAdresowa::wylogujUzytkownika()
{
    uzytkownikMenedzer.wylogujUzytkownika();
    kontaktMenedzer.ustawIdZalogowanegoUzytkownika(0);
}

void KsiazkaAdresowa::zmianaHaslaUzytkownika()
{
    uzytkownikMenedzer.zmianaHaslaUzytkownika();
}

void KsiazkaAdresowa::dodajKontakt()
{
    kontaktMenedzer.dodajKontakt();
}

void KsiazkaAdresowa::wyswietlWszytskieKontakty()
{
    kontaktMenedzer.wyswietlWszystkieKontakty();
}

void KsiazkaAdresowa::przekazIdUzytkownikaDoMenadzeraKontaktow()
{
    int id;
    id = uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika();
    kontaktMenedzer.ustawIdZalogowanegoUzytkownika(id);
}
