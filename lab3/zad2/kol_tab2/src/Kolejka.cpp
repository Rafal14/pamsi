#include "Kolejka.hh"
#include <fstream>


Kolejka::Kolejka ( int ilosc ) {
    dlugosc = ilosc;        //określ wielkosc tablicy
    St = new int[ilosc];    //tablica alokowana dynamicznie
    indeks = 0;
    przod = 0;
    tyl = 0;
  }

//zwraca rozmiar kolejki
int Kolejka::rozmiar() { 
  return indeks;
}

//sprawdza czy kolejka jest pusta
bool Kolejka::czyPusta() {
  if ( indeks == 0) {
    return true;
  }
  return false;
}

//Zwraca pierwszy element w kolejce
int Kolejka::pierwszy() {
  return St[przod];    //  St[f],  warunek spr czy pusta
}

//usuwa element z kolejki,   usuwa pierwszy element 
bool Kolejka::UsunElem() {
  if (czyPusta()==true) {
    cout << "Nie można usunąć elementu. Kolejka jest pusta"
	 << endl << endl;
    return false;
  }
  przod = (przod + 1) % dlugosc;
  --indeks;
  return true;
}


//dodaje element do kolejki
int Kolejka::DodajElem ( const int &wartosc  )
{
  if (rozmiar() == dlugosc ) {
    int *Tab = new int[dlugosc*2]; // nowa większa tablica
    for ( int i=0; i < dlugosc; ++i) {
      Tab[i] = St[i];
    }
    ++tyl;
    Tab[tyl] = wartosc;
    ++indeks;
    dlugosc*=2;

    //-----------------------------------------------------------
    int ind = indeks;
    int prz = przod;       //zapamietanie aktualnych indeksów
    int t   = tyl;
    int d = dlugosc;
    //----------------------------------------------------------

    delete []St;                       //usuń poprzednią tablice  
    St = Tab;              //     zapisz powiekszoną tablica 
    indeks = ind;
    przod = prz;
    tyl = t;  
    dlugosc = d;   
    return 0;
  }
  //wpisz element 
  St[tyl] = wartosc;
  tyl = (tyl + 1) % dlugosc;
  ++indeks;
  return 0;
}
 

// usuwa wszystkie elementy z kolejki
bool Kolejka::UsunWszystkie ()
{
  if (czyPusta()==true) {
    cout << "Błąd. Kolejka jest pusta"
	 << endl;
    return false;
  }
  while (!czyPusta() ) {
    UsunElem();
  }
  cout << "Usunięto wszystkie elementy z kolejki" << endl;
  return true;
}


//wyswietla zawartość kolejki
void Kolejka::WyswietlZawart ()
{
  if (czyPusta()!=true) {
    for (int i=0; i< rozmiar(); ++i) {
      cout << St[i] << endl;
    }
  }
  else
    cout << "Kolejka jest pusta" << endl;
}


// dodaje elementy losowe do kolejki
void DodajLos(const string &NazwaPliku, Kolejka &Kol)
{
  ifstream PlikWej;                //utwórz strumień wejściowy dla pliku
  int liczba_losowa;              //wartość odczytna z pliku
  int rozmiar = 0 ;               //ilość elementów w pliku
  PlikWej.open ( NazwaPliku, fstream::in );
  for (; !PlikWej.eof(); ++rozmiar) {
    PlikWej >> liczba_losowa;
    Kol.DodajElem(liczba_losowa);     //wpisanie liczby do kolejki
  }
  PlikWej.close();                         //zamknij strumień
}
