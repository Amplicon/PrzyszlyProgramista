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
