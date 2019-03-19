#include "UzytkownikMenedzer.h"

void UzytkownikMenedzer::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();
    uzytkownicy.push_back(uzytkownik);
    plikUzytkownicy.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;

    uzytkownik.ustawId( pobierzIdNowegoUzytkownika());
    string login, haslo;
    do
    {
        cout << "Podaj login: ";
        login = MetodyPomocnicze::wczytajLinie();
        uzytkownik.ustawLogin(login);
    }
    while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    cout << "Podaj haslo: ";
    haslo = MetodyPomocnicze::wczytajLinie();
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

int UzytkownikMenedzer::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;

    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenedzer::czyIstniejeLogin(string login)
{
    for(unsigned i=0; i<uzytkownicy.size(); i++)
    {
        if(uzytkownicy[i].pobierzLogin()==login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;

        }
    }
    return false;
}

void UzytkownikMenedzer::wczytajUzytkownikowZPliku()
{
    uzytkownicy = plikUzytkownicy.wczytajUzytkownikowZPliku();
}

int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}

void UzytkownikMenedzer::logowanieUzytkownika()
{
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    login = MetodyPomocnicze::wczytajLinie();

    for (unsigned i=0; i<uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = MetodyPomocnicze::wczytajLinie();

                if (uzytkownicy[i].pobierzHaslo() == haslo)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    idZalogowanegoUzytkownika=uzytkownicy[i].pobierzId();
                    system("pause");
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}

bool UzytkownikMenedzer::zalogowanyUzytkownik()
{
    bool statusUzytkownika=false;

    if( pobierzIdZalogowanegoUzytkownika()>0)
    {
        statusUzytkownika=true;
        return statusUzytkownika;
    }
    else if(pobierzIdZalogowanegoUzytkownika()==0)
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

void UzytkownikMenedzer::wylogujUzytkownika()
{
    idZalogowanegoUzytkownika=0;
}

void UzytkownikMenedzer::zmianaHaslaUzytkownika()
{
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = MetodyPomocnicze::wczytajLinie();

    for (unsigned i=0; i<uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzId() == idZalogowanegoUzytkownika)
        {
            uzytkownicy[i].ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            Sleep(500);
        }
    }
    plikUzytkownicy.aktualizujPlikUzytkownicy(uzytkownicy);
}
