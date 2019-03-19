#include "MetodyPomocnicze.h"

string MetodyPomocnicze::konwerjsaIntNaString(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

string MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst)
{
    if (!tekst.empty())
    {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}

string MetodyPomocnicze::wczytajLinie()
{

    string wejscie ;

    getline(cin,wejscie);


    return wejscie;

}

char MetodyPomocnicze::wczytajZnak()
{
    char wejscie;
    cin.get(wejscie);
    cin.clear();
    cin.ignore(numeric_limits<char>::max(),'\n'); //ignores EVERYTHING in input buffer up to newline character
    return wejscie;

}

int MetodyPomocnicze::wczytajLiczbe()
{
    string wejscie = "";
    int liczba = 0;

    while (true)
    {
        getline(cin, wejscie);
        stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
return liczba;
}

int MetodyPomocnicze::konwersjaStringNaInt(string linia)
{
    int liczbaInt;
    istringstream iss(linia);
    iss >> liczbaInt;

    return liczbaInt;
}
string MetodyPomocnicze::pobierzLiczbe(string linia, int pozycjaZnaku)
{
    string liczba = "";
    while(isdigit(linia[pozycjaZnaku]) == true)
    {
        liczba += linia[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}
