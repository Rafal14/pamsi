#ifndef KOLEJKA_HH
#define KOLEJKA_HH

/*!
 *
 * Plik zawiera definicje funkcji działających na kolejce
 */

#include <iostream>


using namespace std;

class Kolejka {
  int dlugosc;    //indeks dlugosc kolejki
  int indeks;     //indeks ostatniego elementu, [  n  ]
  int przod;     // infeks f kolejki 
  int tyl;       // indeks r kolejki,   r = ostatni elem + 1
  int *St;       //wskaźnik na tablice

public:
  //konstruktor parametryczny
  Kolejka ( int ilosc );
  ~Kolejka ()   { delete []St; } //destruktor
  int rozmiar();           //zwraca rozmiar kolejki
  bool czyPusta();          //gdy kolejka jest pusta
  int pierwszy();    //zwraca wartość pierw elementu
  bool UsunElem();   //usuwa element z kolejki
  int DodajElem( const int &wartosc);    //dodaje element do kolejki
  bool UsunWszystkie ();
  void WyswietlZawart ();
};

using namespace std;


//dodaje wartości losowe z pliku do kolejki
void DodajLos(const string &NazwaPliku, Kolejka &Kol);

#endif
