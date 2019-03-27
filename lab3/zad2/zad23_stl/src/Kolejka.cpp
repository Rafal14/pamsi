#include "Kolejka.hh"
#include <queue>
#include <fstream>


// usuwa wybrane element z kolejki
bool UsunElem( queue<int> &Ko )
{
  if ( Ko.empty() ) {
    cout << "Blad. Kolejka jest pusta."
	 << endl << endl;
    return false;
  }
  Ko.pop();
  return true;
}
  
 
//dodaje element do kolejki
void DodajElem ( queue<int> &Ko, int wartosc  )
{
  Ko.push(wartosc);
  cout << endl << "Dodano element " << wartosc
       << " do kolejki" << endl << endl;
}
 

// usuwa wszystkie elementy z kolejki
bool UsunWszystkie ( queue<int> &Ko )
{
  //jeżeli kolejka jest pusta
  if (Ko.empty()) { 
    return false;
  }
  //usuń wszystkie elementy kolejki 
  while ( !Ko.empty() )
    {
      Ko.pop();
    }
  cout << endl << "Usunięto wszystkie elementy kolejki." << endl;
  return true;
}


//wyswietla zawartość kolejki
void WyswietlZawart (queue<int> &Ko)
{
  if ( Ko.empty() ) { cout << endl << "Kolejka pusta" << endl << endl;}
  else {
    unsigned int rozmiar = Ko.size();  //rozmiar wyswietlanej kolejki
    //alokacja tablicy pomocniczej
    int* tab = new int[rozmiar];
    cout << endl << "Zawartość kolejki" << endl;

    //przenieś kolejkę do tablicy
    for ( unsigned int i = rozmiar; i>0; --i) {
      tab[i-1]=Ko.front();
      cout << " " << tab[i-1];        //wyswietlenie kolejki
      Ko.pop();
    }
    for ( unsigned int j = rozmiar; j>0; --j) {
      Ko.push(tab[j-1]);                    //umiesza elementy w kolejce
    }
    delete[] tab;       //usuń tablicę pomocniczą
  }
}


// dodaje elementy losowe do kolejki
void DodajLos(const string &NazwaPliku, queue<int> &Ko)
{
  ifstream PlikWej;                //utwórz strumień wejściowy dla pliku
  int liczba_losowa;              //wartość odczytna z pliku
  int rozmiar = 0 ;               //ilość elementów w pliku
  PlikWej.open ( NazwaPliku, fstream::in );
  for (; !PlikWej.eof(); ++rozmiar) {
    PlikWej >> liczba_losowa;
   Ko.push(liczba_losowa);         //wpisanie liczby do kolejki
  }
  PlikWej.close();                         //zamknij strumień
}
