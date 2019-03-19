#include "KontaktMenedzer.h"

void KontaktMenedzer::dodajKontakt()
{

    system("cls");
    cout << " >>> DODAWANIE NOWEGO KONTAKTU <<<" << endl << endl;
    Kontakt nowyKontakt = podajDaneNowegoKontaktu();

    kontakty.push_back(nowyKontakt);
    plikKontakty.dopiszKontaktDoPliku(nowyKontakt);

    return;

}
void KontaktMenedzer::wyswietlWszystkieKontakty()
{
    system("cls");
    for(unsigned i=0; i<kontakty.size(); i++)
    {
        wyswietlDaneKontaktu(kontakty[i]);
    }
    return;
}

void KontaktMenedzer::wyswietlDaneKontaktu(Kontakt kontakt)
{

    cout << endl << "Id:                 " << kontakt.pobierzId() << endl;
    cout << "Imie:               " << kontakt.pobierzImie() << endl;
    cout << "Nazwisko:           " << kontakt.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << kontakt.pobierzTelefon() << endl;
    cout << "Email:              " << kontakt.pobierzEmail() << endl;
    cout << "Adres:              " << kontakt.pobierzAdres() << endl;
}

Kontakt KontaktMenedzer::podajDaneNowegoKontaktu()
{
    Kontakt kontakt;
    string imie="", nazwisko="", telefon="", email="", adres="";
    kontakt.ustawId( pobierzIdNowegoKontaktu() );
    kontakt.ustawIdUzytkownika( ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Podaj imie: ";
    imie = MetodyPomocnicze::wczytajLinie();
    imie = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);
    kontakt.ustawImie(imie);

    cout << "Podaj nazwisko: ";
    nazwisko= MetodyPomocnicze::wczytajLinie();
    nazwisko = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);
    kontakt.ustawNazwisko(nazwisko);

    cout << "Podaj numer telefonu: ";
    telefon = MetodyPomocnicze::wczytajLinie();
    kontakt.ustawTelefon(telefon);

    cout << "Podaj email: ";
    email = MetodyPomocnicze::wczytajLinie();
    kontakt.ustawEmail(email);

    cout << "Podaj adres: ";
    adres = MetodyPomocnicze::wczytajLinie();
    kontakt.ustawAdres(adres);

    return kontakt;
}


int KontaktMenedzer::pobierzIdNowegoKontaktu()
{
    if (kontakty.empty() == true)
        return 1;
    else
        return kontakty.back().pobierzId() + 1;
}
void KontaktMenedzer::usunKontakt(int idKontaktu)
{
    for(unsigned i=0; i<kontakty.size(); i++)
    {
        if(kontakty[i].pobierzId()==idKontaktu)
        {
            kontakty.erase(kontakty.begin()+i);
            plikKontakty.usunKontaktZPliku(idKontaktu, ID_ZALOGOWANEGO_UZYTKOWNIKA);
            return;
        }
    }
    system("cls");
    cout<<"Nie znaleziono kontaktu o podanym ID!";
    Sleep(1000);
    return;
}

void KontaktMenedzer::wyszukajImie(string imie)
{
    system("cls");
    bool znaleziono=false;
    for(unsigned i=0; i<kontakty.size(); i++)
    {
        if(imie==kontakty[i].pobierzImie())
        {
            wyswietlDaneKontaktu(kontakty[i]);
            znaleziono=true;
        }
    }
    if(znaleziono==false)
    {
        cout<<"Nie znaleziono imienia : "<<imie<<endl;
    }
    system("pause");
    return;
}

void KontaktMenedzer::wyszukajNazwisko(string nazwisko)
{
    system("cls");
    bool znaleziono=false;
    for(unsigned i=0; i<kontakty.size(); i++)
    {
        if(nazwisko==kontakty[i].pobierzNazwisko())
        {
            wyswietlDaneKontaktu(kontakty[i]);
            znaleziono=true;
        }
    }
    if(znaleziono==false)
    {
        cout<<"Nie znaleziono nazwiska : "<<nazwisko<<endl;
    }
    system("pause");
    return;
}

void KontaktMenedzer::edytujKontakt(int idKontaktu, char wybor)
{
    system("cls");
    for(unsigned i=0; i<kontakty.size(); i++)
    {
        if(kontakty[i].pobierzId()==idKontaktu)
        {
            switch(wybor)
            {
            case '1':

                cout<<"WPROWADZ IMIE: ";

                kontakty[i].ustawImie(MetodyPomocnicze::wczytajLinie());

                break;

            case '2':

                cout<<"WPROWADZ NAZWISKO: ";

                kontakty[i].ustawNazwisko(MetodyPomocnicze::wczytajLinie());
                break;

            case '3':

                cout<<"WPROWADZ NUMER TELEFONU: ";

                kontakty[i].ustawTelefon(MetodyPomocnicze::wczytajLinie());
                break;

            case '4':

                cout<<"WPROWADZ ADRES: ";

                kontakty[i].ustawAdres(MetodyPomocnicze::wczytajLinie());
                break;

            case '5':

                cout<<"WPROWADZ E-MAIL: ";

                kontakty[i].ustawEmail(MetodyPomocnicze::wczytajLinie());
                break;

            case '6':

                usunKontakt(idKontaktu);
                return;;

            }
            plikKontakty.aktualizujPlikKontakty(kontakty[i]);
            return;
        }
    }
    cout<<"Nie znaleziono Kontaktu o podanym ID ("<<idKontaktu<<") !"<<endl;
    Sleep(1000);
    return;

}
