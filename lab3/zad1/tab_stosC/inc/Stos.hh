#ifndef STOS_HH
#define STOS_HH

/*!
 *
 * Plik zawiera definicje metod działających na stosie
 */

#include <iostream>

using namespace std;


class Stos {
  int szczyt;    //indeks szczytu stosu
  int pojemnosc;     //maksymalna liczba elementów na stosie
  int *St;       //wskaźnik na tablice

public:
  //konstruktor parametryczny
  Stos ( int ilosc ) {
    pojemnosc = ilosc;     //określ wielkosc tablicy
    St = new int[ilosc];    //tablica alokowana dynamicznie
    szczyt = -1;    //zainicjowanie szczytu stosu (brak elementów )
  }
  ~Stos() { delete []St; } //destruktor
  //metoda zwraca rozmiar stosu
  int rozmiar();
 
  //sprawdza czy stos jest pusty
  bool czyPusty();

  int gora();                //zwraca elem na szczycie stosu
  //usuwa element ze stosu
  int UsunElem();
  //odkłada element na stosie
  void DodajElem(const int &element);
  //wyswietl zawartosc stosu

  // wyświetla zawartość stosu
  void WyswietlZawart();

};


//dodaje wartości losowe do stosu
void DodajLos(const string &NazwaPliku, Stos &Obiekt); 

#endif
