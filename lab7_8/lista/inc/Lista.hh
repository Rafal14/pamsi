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
  //dodaje elem z przodu listy
  void DodajNapocz(const T &el, const T &indv, const T &indw);
  //usuwa i zwraca element z przodu listy jednokier
  T UsunZprzodu(T &wierz1, T &wierz2);         
  //usuwa i zwraca element z przodu listy jednokier
  //   T UsunZtylu();             // usuwa element z tylu listy
  void DodajZtylu (const T &el, const T &indv, const T &indw);  
  void Wyswietl();              //wyświetla zawartość listy jednokierunkowej
  int rozmiar() const;               // zwraca ilosc elementow w liscie
  T pierwszy();                 // zwraca pierwszy element z listy
  T ostatni();                  // zwraca ostatni element z listy
  T minimum();                     // znajduje minimum
  T Znajdz( const int &ind  );      // zwraca okreslony elem z listy
  bool CzyNieMalejacy();          // sprawdza czy ciag jest niemalejacy

  void DodajElem (const T &el, const T &indv, const T &indw );
     //dodaje elem do kolejki priorytetowej
};



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
void Lista<T>::DodajNapocz  (const T &el, const T &indv, const T &indw )
{
  Wezel<T>* obiekt = new Wezel<T>;    //alokacja nowego wezła listy
  
  if ( glowa == NULL ) {
    ogon = obiekt;
  }

  obiekt->element = el;        //wpisz nowy element do węzła listy
  //--------------------------------------------
  obiekt-> wierz_v = indv;     //dodanie ind wierzcholka
  obiekt-> wierz_w = indw;     //dodanie ind wierzcholka
 //-------------------------------------------------
  obiekt->nastepny = glowa;   //wskazanie na następny element       
  glowa = obiekt;            //niech glowa pokazuje na nowy obiekt
  ++dlugosc;
}

//dodaje element na koniec listy jednokierunkowej 
template <typename T>
void Lista<T>::DodajZtylu (const T &el, const T &indv, const T &indw )
{
  Wezel<T>* obiekt = new Wezel<T>;    //alokacja nowego wezła listy
  obiekt->element = el;
 //--------------------------------------------
  obiekt->wierz_v = indv;     //dodanie ind wierzcholka
  obiekt->wierz_w = indw;     //dodanie ind wierzcholka
 //-------------------------------------------------
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
T Lista<T>::UsunZprzodu(T &wierz1, T &wierz2)
{
  //pierwszy element z listy
  Wezel<T>* usuwanyWezel = glowa;
  //głowa listy wskazuje na następny element z listy
  T elem = glowa->element;
  wierz1 = glowa->wierz_v;
  wierz2 = glowa->wierz_w;
  glowa = usuwanyWezel->nastepny;
  delete usuwanyWezel; //usunięcie pierwszego elementu z listy
  --dlugosc;
  return elem;           //zwraca usuwany element
}   


//wyświetla zawartość listy jednokierunkowej
template <typename T>
void Lista<T>::Wyswietl() 
{
if ( czyPusta() == false ) {
  Wezel<T>* wskaz = glowa;
  while ( (wskaz->nastepny)!=NULL ) {
    cout << wskaz->wierz_v << "\t" << wskaz->wierz_w << "\t" << wskaz->element;
    cout << endl;
    wskaz = wskaz->nastepny;
  }
  cout << wskaz->wierz_v << "\t" << wskaz->wierz_w << "\t" << wskaz->element;
  cout << endl << endl;
 }
 else
   cout << "Tablica pusta." << endl;
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




template <typename T>
void Lista<T>::DodajElem (const T &el, const T &indv, const T &indw ) 
//dodaje elem do kolejki priorytetowej
{
  if ( dlugosc == 0 ) {
    DodajNapocz(el, indv, indw );   //dodanie do kolejki priorytetowej 1. elem
  }
  else { 
    if ( el <= pierwszy() ) {
      DodajNapocz(el, indv, indw ); // dodanie na pocz kolejki
    }
    else if ( el > pierwszy() ) {
      if ( el >= ostatni() ) {
	DodajZtylu(el, indv, indw ); // dodanie na pocz kolejki
      }
      else {
	// dodanie elementu do srodka kolejki
	Wezel<T>* obiekt = new Wezel<T>;    //alokacja nowego wezła listy

	obiekt->element = el;        //wpisz nowy element do węzła listy
	//--------------------------------------------
	obiekt-> wierz_v = indv;     //dodanie ind wierzcholka
	obiekt-> wierz_w = indw;     //dodanie ind wierzcholka
	//-------------------------------------------------

	++dlugosc;
       
	//umieszenie elementu w kolejce
	Wezel<T>* wskaz = glowa->nastepny;        //utworzenie wskaznika
	Wezel<T>* pop = glowa;        //utworzenie wskaznika
 
	T nast;

	nast = wskaz->element;
	// wykonaj tak dlugo az element nastepny nie bedzie wiekszy od el	
        for (; nast < el ; ) {
	  pop = wskaz;
	  wskaz = wskaz->nastepny;
	  nast = wskaz->element;
	}
	pop->nastepny = obiekt;
	obiekt->nastepny = wskaz;
      }
    }
  }
}




//-----------------------------------------------------
// zapisywnie tablicy zmierzonych czasów do pliku
bool ZapiszDoPliku (string nazwa, int *tab );


// Zwraca średnia średni czas trwania sortowania
int ObliczSrednia ( string nazwa );

    


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
