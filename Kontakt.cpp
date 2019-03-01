#include "Kontakt.h"

    void Kontakt::ustawIdUzytkownika(int idUzytkownika)
    {
        this -> idUzytkownika = idUzytkownika;
    }
    void Kontakt::ustawId(int id)
    {
        this -> id = id;
    }
    void Kontakt::ustawImie(string imie)
    {
        this -> imie = imie;
    }
    void Kontakt::ustawNazwisko(string nazwisko)
    {
        this -> nazwisko = nazwisko;
    }
    void Kontakt::ustawAdres(string adres)
    {
        this -> adres = adres;
    }
    void Kontakt::ustawTelefon(string telefon)
    {
        this -> telefon = telefon;
    }
    void Kontakt::ustawEmail(string email)
    {
        this -> email = email;
    }
    int Kontakt::pobierzIdUzytkownika()
    {
        return idUzytkownika;
    }

    int Kontakt::pobierzId()
    {
        return id;
    }
    string Kontakt::pobierzImie()
    {
        return imie;
    }
    string Kontakt::pobierzNazwisko()
    {
        return nazwisko;
    }
    string Kontakt::pobierzAdres()
    {
        return adres;
    }
    string Kontakt::pobierzTelefon()
    {
        return telefon;
    }
    string Kontakt::pobierzEmail()
    {
        return email;
    }

