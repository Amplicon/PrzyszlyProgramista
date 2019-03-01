#ifndef PLIKKONTAKTY_H
#define PLIKKONTAKTY_H


#include<iostream>

using namespace std;

class PlikKontakty
{
   const string nazwaPlikuZKontaktami;

   public:
PlikKontakty(string NAZWAPLIKUZKONTAKTAMI):nazwaPlikuZKontaktami(NAZWAPLIKUZKONTAKTAMI){cout<<NAZWAPLIKUZKONTAKTAMI;};//lista inicjalizacyjna do const nazwaPlikuZUzytkownikami;

};

#endif // PLIKKONTAKTY_H
