#ifndef LISTA_HH
#define LISTA_HH

/*!
 * \file
 * \brief Definicja klasy Lista
 *
 * Plik zawiera definicje klasy metod dostępu do listy jednokierunkowej
 * przechowujący elementy dowolnego typu
 */


#include "Wezel.hh"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
 #include <cmath>

using namespace std;


/*!
 * \brief Modeluje pojęcie listy jednokierunkowej
 *
 *
 * Klasa modeluje pojęcie listy jednokierunkowej
 * zawierającej elementy dowolnego typu.
 *
 */
template <typename T>
class Lista {
private:
  Wezel<T>* glowa;         //wskaźnik na głowe listy jednokierunkowej
  Wezel<T>* ogon;          //wskaźnik na ostatni element listy
  int dlugosc;          //ilość elementów na liście

public:
  //bezparametryczny konstruktor klasy 
  Lista() {glowa = NULL; ogon = NULL; dlugosc = 0; }

  //destruktor listy
  //~Lista() { while(!czyPusta()) {UsunZprzodu();}
  //  cout << "Usunieto Liste"<< endl << "----------------------"  << endl;}  
  bool czyPusta() const;           //czy lista jednokierunkowa jest pusta
  void DodajNapocz(const T &el);     //dodaje elem z przodu listy
  T UsunZprzodu();            //usuwa i zwraca element z przodu listy jednokier
  //   T UsunZtylu();             // usuwa element z tylu listy
  void DodajZtylu (const T &el);    //dodaje z tylu element     
  void Wyswietl();              //wyświetla zawartość listy jednokierunkowej
  int rozmiar() const;               // zwraca ilosc elementow w liscie
  T pierwszy();                 // zwraca pierwszy element z listy
  T ostatni();                  // zwraca ostatni element z listy
  T minimum();                     // znajduje minimum
  T Znajdz( const int &ind  );      // zwraca okreslony elem z listy
  bool CzyNieMalejacy();          // sprawdza czy ciag jest niemalejacy
};

// generuje i dodaje wartości losowe do listy jednokierunkowej
template <typename T>
void GenerujWartosciLosowe (const int &przedzial, Lista<T> &Obiekt)
{
  int liczba_losowa;
  for ( int i = 0 ; i < przedzial; ++i ) { 
    liczba_losowa = rand() % przedzial;          //wyznaczenie liczby losowej
    Obiekt.DodajZtylu(liczba_losowa);
  }
}

// generuje i dodaje wartości losowe do tablicy
template <typename T>
void GenerujLosowe (const int &przedzial, T* tabLiczb )
{
  int liczba_losowa;
  for ( int i = 0 ; i < przedzial; ++i ) { 
    liczba_losowa = rand() % przedzial;          //wyznaczenie liczby losowej
    tabLiczb[i] = liczba_losowa;
  }
}    

// sprawdza czy lista jest pusta
template <typename T>
bool Lista<T>::czyPusta() const
{
  if (glowa == NULL ) 
    return true;
  else
    return false;
}



//dodaje element na początku listy jednokierunkowej
template <typename T>
void Lista<T>::DodajNapocz  (const T &el )
{
  Wezel<T>* obiekt = new Wezel<T>;    //alokacja nowego wezła listy
  
  if ( glowa == NULL ) {
    ogon = obiekt;
  }

  obiekt->element = el;        //wpisz nowy element do węzła listy  
  obiekt->nastepny = glowa;   //wskazanie na następny element       
  glowa = obiekt;            //niech glowa pokazuje na nowy obiekt
  ++dlugosc;
}

//dodaje element na koniec listy jednokierunkowej 
template <typename T>
void Lista<T>::DodajZtylu (const T &el)
{
  Wezel<T>* obiekt = new Wezel<T>;    //alokacja nowego wezła listy
  obiekt->element = el;
  if ( glowa == NULL ) {       
    glowa = obiekt;            //warunek dla pierwszego elementu
    ogon = obiekt;   //głowa i ogon wskazują na pierwszy element
  }
  else {
    ogon->nastepny = obiekt;  //dowiązanie do następnego elementu
    ogon = obiekt;         //ogon wskazuje na ostatnio dodany element
  }
  ++dlugosc;
}

//usuwa element z początku listy
template <typename T>
T Lista<T>::UsunZprzodu()
{
  //pierwszy element z listy
  Wezel<T>* usuwanyWezel = glowa;
  //głowa listy wskazuje na następny element z listy
  glowa = usuwanyWezel->nastepny;
  T elem = usuwanyWezel->element;
  delete usuwanyWezel; //usunięcie pierwszego elementu z listy
  --dlugosc;
  return elem;           //zwraca usuwany element
}   


//wyświetla zawartość listy jednokierunkowej
template <typename T>
void Lista<T>::Wyswietl() 
{
  Wezel<T>* wskaz = glowa;
  while ( (wskaz->nastepny)!=NULL ) {
    cout << wskaz->element;
    cout << endl;
    wskaz = wskaz->nastepny;
  }
  cout << wskaz->element;
  cout << endl << endl;
 
}


// zwraca ilość elementów znajdujących się w liście
template <typename T>
int Lista<T>::rozmiar() const
{
  return dlugosc;
}

// zwraca wartość elementu znajdującego się na początku listy
template <typename T>
T Lista<T>::pierwszy()
{
  return glowa->element;
}

// zwraca wartość elementu znajdującego się na końcu listy
template <typename T>
T Lista<T>::ostatni()
{
  return ogon->element;
}


// znajduję wartość najmniejszą w liście
template <typename T>
T Lista<T>::minimum()
{
  // int licz = 0;
  Wezel<T>* wskaz = glowa;
  T poprzedni = glowa->element;
  T nast;
  while ( wskaz->nastepny != NULL ) {
    wskaz = wskaz->nastepny;
    nast  = wskaz->element;
    if ( nast < poprzedni ) {
      poprzedni = nast;        // nowy komparator
    }
  }
  return poprzedni;
}

//Sprawdza czy wartości znajdujące się w liście tworzą ciąg niemalejący
template <typename T>
bool Lista<T>::CzyNieMalejacy() // sprawdza czy ciag jest niemalejący
{
  Wezel<T>* wskaz = glowa;
  T poprzedni = glowa->element;
  T nast;
  while ( wskaz->nastepny != NULL ) {
    wskaz = wskaz->nastepny;
    nast  = wskaz->element;
    if ( poprzedni > nast ) {
      return false;
    }
    else
      poprzedni = nast;
  }
  return true;
}

//Zwraca wartość okreslonego element z listy
template <typename T>
T Lista<T>::Znajdz( const int &ind  )
{
  // int licz = 0;
  Wezel<T>* wskaz = glowa;
  T nast;
  for ( int i=0; i<ind; ++i) {
    if  ( wskaz->nastepny != NULL ) {
      nast  = wskaz->element;
      wskaz = wskaz->nastepny;
    }
  }
  nast  = wskaz->element;
  return nast;
}


// -------------------------------------------------------------



// Scala dwie posortowane listy w jedną liste 
template <typename T>
Lista<T> Scal ( Lista<T> Lista1, Lista<T> Lista2, int komparator )
{
  Lista<T> Suma, Pom;
  T elem;
  while  ( (Lista1.rozmiar() > 0) || (Lista2.rozmiar() > 0) ) {
    if ( (Lista1.rozmiar() > 0) && (Lista2.rozmiar() > 0) ) {
      
      if ( (Lista1.pierwszy()) <= (Lista2.pierwszy()) ) {
	// Uporządkuj elementy od najmniejszego do największego
	if ( komparator == 0 ) {
	  Suma.DodajZtylu( Lista1.pierwszy() );
	  Lista1.UsunZprzodu();
	}
	// Uporządkuj elementy od największego do najmniejszego
	if (komparator == 1) {
	  Suma.DodajZtylu( Lista2.pierwszy() );
	  Lista2.UsunZprzodu();
	}
      }
      else {
	// Uporządkuj elementy od najmniejszego do największego
	if ( komparator == 0 ) {
	  Suma.DodajZtylu( Lista2.pierwszy() );
	  Lista2.UsunZprzodu();
	}
	// Uporządkuj elementy od największego do najmniejszego
	if (komparator == 1) {
	  Suma.DodajZtylu( Lista1.pierwszy() );
	  Lista1.UsunZprzodu();
	}
      }
    }
    else if ( Lista1.rozmiar() > 0) {
      Pom = Lista1;
      for (int i = 0; i < Lista1.rozmiar(); ++i) {
	elem = Pom.UsunZprzodu();
	Suma.DodajZtylu(elem);
      }
      break;
    } else if (  Lista2.rozmiar() > 0 ) {
      Pom = Lista2;
      for (int j = 0; j < Lista2.rozmiar(); ++j) {
	elem = Pom.UsunZprzodu();
	Suma.DodajZtylu(elem);
      }
      break;
    }
  }
  return Suma;
}

 

// Zasadnicza funkcja sortowania przez scalanie
template <typename T>
Lista<T> Sortuj_scal (  Lista<T> Zestaw, int komp )
{
  // zwróć wartość gdy lista jest jednoelementowa
  if ( Zestaw.rozmiar() <=1 ) 
    return Zestaw;

  Lista<T> Zestaw1, Zestaw2, Zest, Pom;
  Pom = Zestaw;             // kopia calej listy
  T el;                     // element pomocniczy
  int srodek = ( Zestaw.rozmiar() + 1 ) / 2;

  // podziel nieposortowane listy na dwie części
  for ( int i = 0; i < srodek; ++i ) {
    el = Pom.UsunZprzodu(); 
    Zestaw1.DodajZtylu( el );
  }

  for ( int j = srodek; j < Zestaw.rozmiar(); ++j ) {
    el = Pom.UsunZprzodu(); 
    Zestaw2.DodajZtylu( el );
  }

  Zestaw1 = Sortuj_scal ( Zestaw1, komp );
  Zestaw2 = Sortuj_scal ( Zestaw2, komp );
  Zest = Scal ( Zestaw1, Zestaw2, komp );

  return Zest;
}



//-----------------------------------------------------
// Quick sort


/*

  
*/

// Sortowanie szybkie - zwraca posortowaną listę
template <typename T> 
Lista<T> QuickSort ( Lista<T> Zestaw, T komparator ) 
{
  // zwroc liste posortowana
  if ( Zestaw.rozmiar() <= 1 )
    return Zestaw;

  T elem;              // element pomocniczy
  int p = ( Zestaw.rozmiar() ) /2;      // wyznaczenie indeksu piwota
  int piwot = Zestaw.Znajdz( p  );      //określenia wartości piwota     

  // L - przechowuje elementy mniejsze od piwota
  // S - przechowuje elementy rowne piwotowi
  // P - przechowuje elementy wieksze od piwota
  Lista<T> L;
  Lista<T> S;
  Lista<T> P;
  Lista<T> Suma;

  // dzieli listę na 3 czesci
  // sprawdź czy zestaw danych nie jest pusty
  // sortuj od najmniejszego do największego
  if ( komparator == 0 )          // sortuj od min do max
    {
      while ( !Zestaw.czyPusta() ) {
	elem = Zestaw.UsunZprzodu();
	if ( elem < piwot ) {
	  L.DodajZtylu(elem);
	}
	else if ( elem == piwot ) {
	  S.DodajZtylu(elem);
	}
	else {
	  P.DodajZtylu(elem);
	}
      }
    }
  //sortuj od największego do najmniejszego
  if ( komparator == 1 ) 
    {
      while ( !Zestaw.czyPusta() ) {
	elem = Zestaw.UsunZprzodu();
	if ( elem > piwot ) {
	  L.DodajZtylu(elem);
	}
	else if ( elem == piwot ) {
	  S.DodajZtylu(elem);
	}
	else {
	  P.DodajZtylu(elem);
	}
      }
    }

  L = QuickSort ( L, komparator );    // posortuj lewa cześć listy
  P = QuickSort ( P, komparator );    // posortuj prawa cześć listy

  // polaczenie list w jedna
  // sortowanie od min do max
    while ( !L.czyPusta() ) {
      elem = L.UsunZprzodu();
      Suma.DodajZtylu( elem );
    }
    while ( !S.czyPusta() ) {
      elem = S.UsunZprzodu();
      Suma.DodajZtylu( elem );
    }
    while ( !P.czyPusta() ) {
      elem = P.UsunZprzodu();
      Suma.DodajZtylu( elem );
    }

  return Suma;    // zwróć posortowaną liste
}


//-----------------------------------------------------
// zapisywnie tablicy zmierzonych czasów do pliku
bool ZapiszDoPliku (string nazwa, int *tab );


// Zwraca średnia średni czas trwania sortowania
int ObliczSrednia ( string nazwa );

    


//---------------------------------------------
// sortowanie Shella
template <typename T>
T* SortowanieShella ( T* tab, int rozmiar, int komparator )
{
  int i, j;
  T tym;          // element tymczasowy

  // liczba elementów w każdym ze zbiorów
  // na które została podzielona tablica
  int odstep = rozmiar/2; 
 
  // dopóki mozna podzielic zbior na 2 podzbiory
  while(odstep) {
    for (i = odstep; i < rozmiar; ++i ) {
      j = i;              // zapamietaj biezacy indeks  
      tym = tab[i];   // zapamietaj
     
      // uporządkuj elementy w tablicy od najmniejszego do największego
      if ( komparator == 0 ) {
	for (j=i; ( j >= odstep)  && ( tab[j-odstep] > tym ); j -= odstep ) {
	  tab[j] = tab[j - odstep];
	}
	tab[j] = tym;
      }
      // uporządkuj elementy w tablicy od największego do najmniejszego
      if ( komparator == 1 ) {
	for (j=i; ( j >= odstep)  && ( tab[j-odstep] < tym ); j -= odstep ) {
	  tab[j] = tab[j-odstep];
	}
	tab[j] = tym;
      }
    }
    odstep = odstep/2;
  }
  return tab;
}



// Sprawdza czy element tablicy tworzą ciąg niemalejący
template <typename T>
bool SprawCzyNieMal( T *wsk, int dlugosc )
{
  T nast, pop;
  for ( int i = 1; i < dlugosc; ++i) {
    pop = wsk[i-1];
    nast = wsk[i];
    if ( pop > nast ) {
      return false;         // ciąg jest nierosnący
    }
  }
  return true;         // ciąg jest niemalejący
}


//Wyświetla tablice
template <typename T>
void WyswietlTab( T *wsk, int dlugosc )
{
  for (int k =0 ; k < dlugosc; ++k ) {
    cout << " " << wsk[k] << " ";
  }
  cout << endl << endl;
}






#endif
