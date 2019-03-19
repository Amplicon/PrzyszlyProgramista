#include "PlikKontakty.h"

string PlikKontakty::przygotujDaneKontaktuDoZapisania(Kontakt kontakt)
{
    string liniaZDanymiKontaktu = "";

    liniaZDanymiKontaktu += MetodyPomocnicze::konwerjsaIntNaString(kontakt.pobierzId()) + '|';
    liniaZDanymiKontaktu += MetodyPomocnicze::konwerjsaIntNaString(kontakt.pobierzIdUzytkownika()) + '|';
    liniaZDanymiKontaktu += kontakt.pobierzImie() + '|';
    liniaZDanymiKontaktu += kontakt.pobierzNazwisko() + '|';
    liniaZDanymiKontaktu += kontakt.pobierzTelefon() + '|';
    liniaZDanymiKontaktu += kontakt.pobierzEmail() + '|';
    liniaZDanymiKontaktu += kontakt.pobierzAdres() + '|';

    return liniaZDanymiKontaktu;
}


void PlikKontakty::dopiszKontaktDoPliku(Kontakt kontakt)
{
    string liniaZDanymiKontaktu = "";
    fstream plikTekstowy;

    plikTekstowy.open(NAZWA_PLIKU_Z_KONTAKTAMI.c_str(), ios::app);

    if (plikTekstowy.good() == true)
    {
        liniaZDanymiKontaktu = przygotujDaneKontaktuDoZapisania(kontakt);

        if (czyPlikJestPusty() == true)
        {
            plikTekstowy << liniaZDanymiKontaktu;
        }
        else
        {
            plikTekstowy << endl << liniaZDanymiKontaktu ;
        }
        plikTekstowy.close();
    }
    else
        cout << "Nie udalo sie otworzyc pliku " << NAZWA_PLIKU_Z_KONTAKTAMI << " i zapisac w nim danych." << endl;
}

void PlikKontakty::aktualizujPlikKontakty(Kontakt kontakt)
{
    string liniaZDanymiKontaktu = "";
    fstream plikTekstowy, tymczasowyPlikTekstowy;
    bool  pierwszaLinia=true;

    plikTekstowy.open(NAZWA_PLIKU_Z_KONTAKTAMI.c_str(), ios::in);
    if (plikTekstowy.good() == true)
    {
        if (czyPlikJestPusty() == true)
        {
            cout<<"Uwaga! Plik jest pusty, brak pozycji do edycji!";
        }
        else
        {
            tymczasowyPlikTekstowy.open((NAZWA_PLIKU_Z_KONTAKTAMI+".TMP").c_str(), ios::app);
            while(getline(plikTekstowy, liniaZDanymiKontaktu) )
            {

                if(pobierzIdKontaktuZLinii(liniaZDanymiKontaktu)==kontakt.pobierzId()//jesli to bedzie 1 kontakt
                        &&pobierzIdUzytkownikaZLinii(liniaZDanymiKontaktu)==kontakt.pobierzIdUzytkownika()&&pierwszaLinia==true)
                {
                    liniaZDanymiKontaktu=przygotujDaneKontaktuDoZapisania(kontakt);
                    tymczasowyPlikTekstowy<<liniaZDanymiKontaktu;
                    pierwszaLinia=false;
                }
                else if(pobierzIdKontaktuZLinii(liniaZDanymiKontaktu)==kontakt.pobierzId()
                        &&pobierzIdUzytkownikaZLinii(liniaZDanymiKontaktu)==kontakt.pobierzIdUzytkownika()&&pierwszaLinia==false)
                {
                    liniaZDanymiKontaktu=przygotujDaneKontaktuDoZapisania(kontakt);
                    tymczasowyPlikTekstowy<<endl<<liniaZDanymiKontaktu;
                }
                else if (pierwszaLinia==true) //jesli to bedzie 1 kontakt
                {
                    tymczasowyPlikTekstowy<<liniaZDanymiKontaktu;
                    pierwszaLinia=false;
                }
                else
                {
                    tymczasowyPlikTekstowy<<endl<<liniaZDanymiKontaktu;
                }
            }
            tymczasowyPlikTekstowy.close();
        }
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku " << NAZWA_PLIKU_Z_KONTAKTAMI << " i zapisac w nim danych." << endl;
        plikTekstowy.close();
        return;
    }
    plikTekstowy.close();
    usunPlik(NAZWA_PLIKU_Z_KONTAKTAMI);
    zmienNazwePliku((NAZWA_PLIKU_Z_KONTAKTAMI+".TMP").c_str(),NAZWA_PLIKU_Z_KONTAKTAMI);
}

void PlikKontakty::usunKontaktZPliku(int idUsuwanegoKontaktu, int idUzytkownika)
{
    fstream plikTekstowy, tymczasowyPlikTekstowy;
    bool usunietyKontakt=false, pierwszaLinia=true;
    string liniaZDanymiKontaktu = "";
    if(czyPlikJestPusty()==false)
    {
        plikTekstowy.open(NAZWA_PLIKU_Z_KONTAKTAMI.c_str(), ios::in);
        if (plikTekstowy.good() == true)
        {
            tymczasowyPlikTekstowy.open((NAZWA_PLIKU_Z_KONTAKTAMI+".TMP").c_str(), ios::app);
            while(getline(plikTekstowy, liniaZDanymiKontaktu) )
            {

                if(pobierzIdUzytkownikaZLinii(liniaZDanymiKontaktu)==idUzytkownika&&
                        pobierzIdKontaktuZLinii(liniaZDanymiKontaktu)==idUsuwanegoKontaktu)
                {
                    usunietyKontakt=true;
                }
                else if (pierwszaLinia==true)
                {
                    tymczasowyPlikTekstowy<<liniaZDanymiKontaktu;
                    pierwszaLinia=false;
                }
                else
                {
                    tymczasowyPlikTekstowy<<endl<<liniaZDanymiKontaktu;
                }
            }
            plikTekstowy.close();
            tymczasowyPlikTekstowy.close();
        }
        else
        {
            cout << "Nie udalo sie otworzyc pliku " << NAZWA_PLIKU_Z_KONTAKTAMI << endl;
            plikTekstowy.close();
            return;
        }
        usunPlik(NAZWA_PLIKU_Z_KONTAKTAMI);
        zmienNazwePliku((NAZWA_PLIKU_Z_KONTAKTAMI+".TMP").c_str(),NAZWA_PLIKU_Z_KONTAKTAMI);
    }
    else
    {
        system("cla");
        cout<<"Uwaga! Plik jest pusty, brak pozycji do usuniecia!";
       // Sleep(1000);
        return;
    }
    if(usunietyKontakt==false)
    {
        system("cla");
        cout<<"Uwaga! Brak pozycji do usuniecia w pliku!";
       // Sleep(1000);
        return;
    }
}

Kontakt PlikKontakty::pobierzDaneKontaktu(string liniaZDanymiKontaktu )
{

    Kontakt kontakt;
    string pojedynczaDanaKontaktu = "";
    int numerPojedynczejDanejKontaktu = 1;

    for (unsigned pozycjaZnaku = 0; pozycjaZnaku < liniaZDanymiKontaktu.length(); pozycjaZnaku++)
    {
        if (liniaZDanymiKontaktu[pozycjaZnaku] != '|')
        {
            pojedynczaDanaKontaktu += liniaZDanymiKontaktu[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejKontaktu)
            {
            case 1:
                kontakt.ustawId (atoi ( pojedynczaDanaKontaktu.c_str() ) );
                break;
            case 2:
                kontakt.ustawIdUzytkownika (atoi ( pojedynczaDanaKontaktu.c_str() ) );
                break;
            case 3:
                kontakt.ustawImie (pojedynczaDanaKontaktu);
                break;
            case 4:
                kontakt.ustawNazwisko (pojedynczaDanaKontaktu);
                break;
            case 5:
                kontakt.ustawTelefon (pojedynczaDanaKontaktu);
                break;
            case 6:
                kontakt.ustawEmail (pojedynczaDanaKontaktu);
                break;
            case 7:
                kontakt.ustawAdres (pojedynczaDanaKontaktu);
                break;
            }
            pojedynczaDanaKontaktu = "";
            numerPojedynczejDanejKontaktu++;
        }
    }
    return kontakt;

}

vector <Kontakt> PlikKontakty::wczytajKontaktyUzytkownika(int ID_ZALOGOWANEGO_UZYTKOWNIKA)
{

    Kontakt kontakt;
    vector <Kontakt> kontakty;
    fstream plikTekstowy;
    string pojedynczaLiniaDanychKontaktu = "";

    plikTekstowy.open(NAZWA_PLIKU_Z_KONTAKTAMI.c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, pojedynczaLiniaDanychKontaktu))
        {
            kontakt = pobierzDaneKontaktu(pojedynczaLiniaDanychKontaktu);
            if(kontakt.pobierzIdUzytkownika()==ID_ZALOGOWANEGO_UZYTKOWNIKA)
            {
                kontakty.push_back(kontakt);
            }
        }
        plikTekstowy.close();
    }
    return kontakty;

}

bool PlikKontakty::czyPlikJestPusty()//here
{
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
}

int PlikKontakty::pobierzIdUzytkownikaZLinii(string liniaZDanymiKontaktu)
{
    int pozycjaRozpoczeciaIdUzytkownika = liniaZDanymiKontaktu.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(liniaZDanymiKontaktu, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}

int PlikKontakty::pobierzIdKontaktuZLinii(string liniaZDanymiKontaktu)
{
    int pozycjaRozpoczeciaIdKontaktu = 0;
    int idKontaktu = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(liniaZDanymiKontaktu, pozycjaRozpoczeciaIdKontaktu));
    return idKontaktu;
}

void PlikKontakty::usunPlik(string nazwaPliku)
{
    if (remove(nazwaPliku.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << nazwaPliku << endl;
}

void PlikKontakty::zmienNazwePliku(string nazwaPliku, string nowaNazwaPliku)
{
    if (rename(nazwaPliku.c_str(), nowaNazwaPliku.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << nowaNazwaPliku << endl;
}

