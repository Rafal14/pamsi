#include "Stos.hh"
#include <stack>
#include <fstream>


// usuwa wybrane elementy ze stosu
bool UsunElem( stack<int> &St, unsigned int elem )
{
  if ( St.empty() ) {
    cout << "Blad. Stos jest pusty."
	 << endl << endl;
    return false;
  }
  else {
    unsigned int rozmiar = St.size();
    //usuń ze szczytu stosu
    if ( elem == rozmiar ) {
      St.pop();
      return true;
    }
    //usuwanie ze środka stosu
    if( elem < rozmiar && elem > 0 ) {
      //zaalokowanie tablicy dynamicznej na elementy stosu
      int* tab = new int[rozmiar - elem];
      for (unsigned int i =( rozmiar - elem); i > 0; --i) {
	tab[i-1] = St.top();
	St.pop();
      }
      St.pop();   // usuń właściwy element
      for (unsigned int j = 0; j <(rozmiar - elem); ++j ) {
	St.push(tab[j]);
      }
      delete[] tab; //usuń tablicę na zdejmowane elem stosu
      return true;
    }

    return false;
  }
}




//dodaje element do stosu
bool DodajElem ( stack<int> &St, unsigned int elem, int wartosc )
{
  //dodanie elementu na szczyt stosu
  if ( elem == 0 ) { 
    St.push(wartosc); 
    return true;
  }
  else {
    unsigned int rozmiar = St.size();      //rozmiar stosu
    //dodanie elem w miejsce dotychczasowego ostatniego elem stosu
    if ( elem == rozmiar ) {
      int dana = St.top();
      St.pop();
      St.push(wartosc);
      St.push(dana); 
      return true;
    }
    //dodanie elementu w środu stosu
    if ( elem > 0  &&  elem < rozmiar ) {
      int* tab = new int[rozmiar - elem];
      for (unsigned int i =( rozmiar - elem); i >0; --i) {
	tab[i-1] = St.top();
	St.pop();
      }
      int dane = St.top();
      St.pop();              //usuń dany element
      St.push(wartosc);      // zamień element
      St.push(dane);
      for (unsigned int j = 0; j <(rozmiar - elem); ++j ) {
	St.push(tab[j]);
      }
      delete[] tab;  //usuwa tablice pomocnicza
      return true;
    }
    cout << "Blad. Nie ma takiej pozycji na stosie."
	 << endl << endl;
    return false;
  }
}

 


// usuwa wszystkie elementy ze stosu
bool UsunWszystkie ( stack<int> &St )
{
  //jeżeli stos jest pusty
  if (St.empty()) { 
    return false;
  }
  //usuń wszystkie elementy stosu
  while ( !St.empty() )
    {
      St.pop();
    }
  cout << endl << "Usunięto wszystkie elementy stosu." << endl;
  return true;
}


//wyswietla zawartość stosu
void WyswietlZawart (stack<int> &St)
{
  if ( St.empty() ) { cout << endl << "Stos pusty" << endl << endl;}
  else {
    unsigned int rozmiar = St.size();  //rozmiar wyswietlanego stosu
    //alokacja tablicy pomocniczej
    int* tab = new int[rozmiar];
    cout << endl << "Zawartość stosu" << endl;

    //przenieś stos do tablicy
    for ( unsigned int i = rozmiar; i>0; --i) {
      tab[i-1]=St.top();
      cout << "\t" << tab[i-1] << endl;        //wyswietlenie stos
      St.pop();
    }
    for ( unsigned int j = 0; j < rozmiar; ++j) {
      St.push(tab[j]);                    //umiesza elementy na stos
    }
    delete[] tab;       //usuń tablicę pomocniczą
  }
}


// dodaje elementy losowe do stosu
void DodajLos(const string &NazwaPliku, stack<int> &St)
{
  ifstream PlikWej;                //utwórz strumień wejściowy dla pliku
  int liczba_losowa;              //wartość odczytna z pliku
  int rozmiar = 0 ;               //ilość elementów w pliku
  PlikWej.open ( NazwaPliku, fstream::in );
  for (; !PlikWej.eof(); ++rozmiar) {
    PlikWej >> liczba_losowa;
    St.push(liczba_losowa);                     //wpisanie liczby na stos
  }
  PlikWej.close();                         //zamknij strumień
}
