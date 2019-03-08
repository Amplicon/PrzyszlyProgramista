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

Kontakt PlikKontakty::pobierzDaneKontaktu(string pojedynczaLiniaDanychKontaktu )
{

    Kontakt kontakt;
    string pojedynczaDanaKontaktu = "";
    int numerPojedynczejDanejKontaktu = 1;

    for (unsigned pozycjaZnaku = 0; pozycjaZnaku < pojedynczaLiniaDanychKontaktu.length(); pozycjaZnaku++)
    {
        if (pojedynczaLiniaDanychKontaktu[pozycjaZnaku] != '|')
        {
            pojedynczaDanaKontaktu += pojedynczaLiniaDanychKontaktu[pozycjaZnaku];
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
