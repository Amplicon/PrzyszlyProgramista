#include "KontaktMenedzer.h"

void KontaktMenedzer::dodajKontakt()
{

    system("cls");
    cout << " >>> DODAWANIE NOWEGO KONTAKTU <<<" << endl << endl;
    Kontakt nowyKontakt = podajDaneNowegoKontaktu();

    kontakty.push_back(nowyKontakt);
    //dopiszKontaktDoPliku(nowyKontakt);

    return;

}
void KontaktMenedzer::wyswietlWszystkieKontakty()
{
    for(unsigned i=0; i<kontakty.size(); i++)
    {
        wyswietlDaneKontaktu(kontakty[i]);


    }
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
    string imie, nazwisko, telefon, email, adres;
    kontakt.ustawId( pobierzIdNowegoKontaktu() );

    cout << "Podaj imie: ";
    cin>>imie;
    imie = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);
    kontakt.ustawImie(imie);

    cout << "Podaj nazwisko: ";
    cin>>nazwisko;
    nazwisko = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);
    kontakt.ustawNazwisko(nazwisko);

    cout << "Podaj numer telefonu: ";
    cin>>telefon;
    kontakt.ustawTelefon(telefon);
    cout << "Podaj email: ";
    cin>>email;
    kontakt.ustawEmail(email);

    cout << "Podaj adres: ";
    cin>>adres;
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
