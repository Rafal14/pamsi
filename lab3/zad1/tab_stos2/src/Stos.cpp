#include "Stos.hh"
#include <cstdlib>
#include <fstream>

//zwraca rozmiar stosu
int Stos::rozmiar()
{
  return pojemnosc;
}

//zwraca elem na szczycie stosu
int Stos::gora()
{
  return St[szczyt];
}

//metoda sprawdzania czy stos jest pusty
bool Stos::czyPusty()
{
  return (szczyt < 0 );    //prawda gdy brak elementów na stosie
}

//usuwa element ze szczytu stosu
int Stos::UsunElem()
{
  if (!czyPusty() ) {
    return St[szczyt--];
  }
  return 1;
}

// Dodaje element do stosu
void Stos::DodajElem(const int &element)
{
  ++szczyt;
  if (szczyt < rozmiar() ) {
    St[szczyt] = element;
  }
  else {
    int *Tab = new int[pojemnosc*2]; // nowa większa tablica
    for ( int i=0; i < pojemnosc; ++i) {
      Tab[i] = St[i];
    }
    Tab[szczyt] = element;
    pojemnosc*=2;
    delete []St;                       //usuń poprzednią tablice
    St = Tab;              //     zapisz powiekszoną tablica
  }
}
  

//wyswietla zawartosc stosu
void Stos::WyswietlZawart()  {
  if ( czyPusty() != true ) { 
    for ( int i=szczyt; i> -1 ; --i) {
      cout << St[i] << endl;
    }
  }
  else 
    cout << "Błąd. Stos jest pusty" << endl;
}


//dodaje wartości losowe do stosu
void DodajLos(const string &NazwaPliku, Stos &Obiekt)
{
  ifstream PlikWej;          //utwórz strumień wejściowy dla pliku
  int liczba_losowa;              //wartość odczytna z pliku
  int rozmiar = 0 ;               //ilość elementów w pliku
  PlikWej.open ( NazwaPliku, fstream::in );
  for (; !PlikWej.eof(); ++rozmiar) {
    PlikWej >> liczba_losowa;
    Obiekt.DodajElem(liczba_losowa);    //wpisanie liczby na stos
  }
  PlikWej.close();                         //zamknij strumień
}
