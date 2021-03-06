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


char KsiazkaAdresowa::menuGlowne()
{

    char wybor = ' ';

    for(;;)
    {
        system("cls");
        cout<<"[======================================================]\n";
        cout<<"|                                                      |\n";
        cout<<"|                    KSIAZKA ADRESOWA                  |\n";
        cout<<"|                                                      |\n";
        cout<<"[==========================+++=========================]\n";
        cout<<"|                                                      |\n";
        cout<<"|1>             Wyswietl wszystkie pozycje            <|\n";
        cout<<"|                                                      |\n";
        cout<<"|                                                      |\n";
        cout<<"|2>             Wyszukaj                              <|\n";
        cout<<"|                                                      |\n";
        cout<<"|                                                      |\n";
        cout<<"|3>             Dodaj pozycje                         <|\n";
        cout<<"|                                                      |\n";
        cout<<"|                                                      |\n";
        cout<<"|4>             Modyfikuj pozycje                     <|\n";
        cout<<"|                                                      |\n";
        cout<<"|                                                      |\n";
        cout<<"|5>             Zmien haslo                           <|\n";
        cout<<"|                                                      |\n";
        cout<<"|                                                      |\n";
        cout<<"|6>             Wyloguj                               <|\n";
        cout<<"|                                                      |\n";
        cout<<"[==========================\\ /=========================]\n";
        cout<<"                            ";

        wybor = MetodyPomocnicze::wczytajZnak();

        if (wybor!='1'&&wybor!='2'&&wybor!='3'&&wybor!='4'&&wybor!='5'&&wybor!='6')
        {
            system("cls");
            cout<<"[======================================================]\n";
            cout<<"|                                                      |\n";
            cout<<"|               Podaj 1, 2, 3, 4, 5 lub 6              |\n";
            cout<<"|                                                      |\n";
            cout<<"[==========================+++=========================]\n";
            cout<<"                            ";

            Sleep(1000);
            system("cls");
        }

        else
        {
            return wybor;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////
char KsiazkaAdresowa::menuLogowania()
{
    char wybor = ' ';

    for(;;)
    {

        system("cls");
        cout<<"[======================================================]\n";
        cout<<"|                                                      |\n";
        cout<<"|                    KSIAZKA ADRESOWA                  |\n";
        cout<<"|                                                      |\n";
        cout<<"[==========================+++=========================]\n";
        cout<<"|                                                      |\n";
        cout<<"|1>             Rejestracja                           <|\n";
        cout<<"|                                                      |\n";
        cout<<"|                                                      |\n";
        cout<<"|2>             >>> Zaloguj...                        <|\n";
        cout<<"|                                                      |\n";
        cout<<"|                                                      |\n";
        cout<<"|3>             Wyjscie z programu                    <|\n";
        cout<<"|                                                      |\n";
        cout<<"[==========================\\ /=========================]\n";
        cout<<"                            ";

        wybor = MetodyPomocnicze::wczytajZnak();

        if (wybor!='1'&&wybor!='2'&&wybor!='3')
        {
            system("cls");
            cout<<"[======================================================]\n";
            cout<<"|                                                      |\n";
            cout<<"|                     Podaj 1, 2, 3                    |\n";
            cout<<"|                                                      |\n";
            cout<<"[==========================+++=========================]\n";
            cout<<"                            ";

            Sleep(1000);
            system("cls");
        }

        else
        {
            return wybor;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////
void KsiazkaAdresowa::menuWyszukiwania()
{

    char wybor = ' ';

    for(;;)
    {

        system("cls");

        cout<<"[======================================================]\n";
        cout<<"|                                                      |\n";
        cout<<"|                        SZUKAJ:                       |\n";
        cout<<"|                                                      |\n";
        cout<<"[==========================/ \\=========================]\n";
        cout<<"|                                                      |\n";
        cout<<"|                                                      |\n";
        cout<<"|1>                      NAZWISKO                      |\n";
        cout<<"|                                                      |\n";
        cout<<"|                                                      |\n";
        cout<<"|2>                      IMIE                          |\n";
        cout<<"|                                                      |\n";
        cout<<"|                                                      |\n";
        cout<<"[==========================\\ /=========================]\n";
        cout<<"                            ";

        wybor = MetodyPomocnicze::wczytajZnak();

        if (wybor!='1'&&wybor!='2')
        {
            system("cls");
            cout<<"[======================================================]\n";
            cout<<"|                                                      |\n";
            cout<<"|                     Podaj 1 lub 2                    |\n";
            cout<<"|                                                      |\n";
            cout<<"[==========================+++=========================]\n";
            cout<<"                            ";

            Sleep(1000);
            system("cls");
        }

        else if (wybor=='1')
        {
            system("cls");
            cout<<"Podaj NAZWISKO do wyszukania: "<<endl;
            string nazwisko = MetodyPomocnicze::wczytajLinie();
            kontaktMenedzer->wyszukajNazwisko(nazwisko);
            return;
        }
        else if (wybor=='2')
        {
            system("cls");
            cout<<"Podaj IMIE do wyszukania: "<<endl;
            string imie = MetodyPomocnicze::wczytajLinie();
            kontaktMenedzer->wyszukajImie(imie);
            return;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////
void KsiazkaAdresowa::menuEdycji()
{
    char wybor = ' ';
    int idKontaktu = 0;

    for(;;)
    {

        system("cls");
        cout<<"[======================================================]\n";
        cout<<"|                                                      |\n";
        cout<<"|                        EDYTUJ:                       |\n";
        cout<<"|                                                      |\n";
        cout<<"[==========================+++=========================]\n";
        cout<<"|                                                      |\n";
        cout<<"|1>             IMIE                                  <|\n";
        cout<<"|                                                      |\n";
        cout<<"|                                                      |\n";
        cout<<"|2>             NAZWISKO                              <|\n";
        cout<<"|                                                      |\n";
        cout<<"|                                                      |\n";
        cout<<"|3>             NUMER TELEFONU                        <|\n";
        cout<<"|                                                      |\n";
        cout<<"|                                                      |\n";
        cout<<"|4>             ADRES                                 <|\n";
        cout<<"|                                                      |\n";
        cout<<"|                                                      |\n";
        cout<<"|5>             E-MAIL                                <|\n";
        cout<<"|                                                      |\n";
        cout<<"|                                                      |\n";
        cout<<"|6>             USUN POZYCJE                          <|\n";
        cout<<"|                                                      |\n";
        cout<<"|                                                      |\n";
        cout<<"|7>             <<< Wroc...                           <|\n";
        cout<<"|                                                      |\n";
        cout<<"[==========================\\ /=========================]\n";
        cout<<"                            ";

        wybor = MetodyPomocnicze::wczytajZnak();

        if (wybor=='7')
            return;

        else if (wybor!='1'&&wybor!='2'&&wybor!='3'&&wybor!='4'&&wybor!='5'&&wybor!='6'&&wybor!='7')
        {
            system("cls");
            cout<<"[======================================================]\n";
            cout<<"|                                                      |\n";
            cout<<"|             Podaj 1, 2, 3, 4, 5, 6 lub 7             |\n";
            cout<<"|                                                      |\n";
            cout<<"[==========================+++=========================]\n";
            cout<<"                            ";

            Sleep(1000);

        }

        else
        {
            system("cls");
            cout<<"Podaj numer kontaktu do edycji: ";
            idKontaktu = MetodyPomocnicze::wczytajLiczbe();

            if(idKontaktu!=0)
            {
                kontaktMenedzer->edytujKontakt(idKontaktu, wybor);
                return;
            }
            else
            {
                system("cls");
                cout<<"NIEPARWIDLOWY NUMER KONTAKTU !!!";
                Sleep(1000);
                return;
            }
        }
    }
}
