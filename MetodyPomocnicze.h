#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H
#include <iostream>
#include <sstream>
#include <algorithm>
#include <limits>

using namespace std;

class MetodyPomocnicze
{
public:

    static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    static string konwerjsaIntNaString(int liczba);
    static int konwersjaStringNaInt(string linia);
    static string pobierzLiczbe(string linia, int pozycjaZnaku);
    static string wczytajLinie();
    static char wczytajZnak();
    static int wczytajLiczbe();


};
#endif //METODYPOMOCNICZE_H
