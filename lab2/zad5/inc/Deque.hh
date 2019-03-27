#ifndef DEQUE_HH
#define DEQUE_HH

/*!
 * \file
 * \brief Definicja klasy Deque
 *
 * Plik zawiera definicje klasy metod dostępu do kolejki deque
 * przechowujący elementy określonego typu
 */


#include "Wezel.hh"
#include <iostream>
#include <string>

using namespace std;


/*!
 * \brief Modeluje pojęcie kolejki o dwóch końcach
 *
 *
 * Klasa modeluje pojęcie kolejki deque
 * zawierającej elementy typu int.
 *
 */
class Deque {

private:
  Wezel* glowa;         //wskaźnik na głowe listy jednokierunkowej
  Wezel* ogon;          //wskaźnik na ostatni element listy
  int dlugosc;          //ilość elementów na liście

public:
  //bezparametryczny konstruktor klasy 
  Deque() {glowa = NULL; ogon = NULL; dlugosc=0;  }

  //destruktor listy
  ~Deque() { while(!czyPusta()) {UsunZprzodu();}}  
  bool czyPusta() const;     //czy lista jednokierunkowa jest pusta
  void DodajNapocz(const char &el);    //dodaje elem z przodu listy
  char UsunZprzodu();      //usuwa element z przodu listy jednokier
  char UsunZtylu();
  void DodajZtylu (const char &el);   //dodaje z tylu element  
  void Wyswietl();     //wyświetla zawartość listy jednokierunkowej
  int  rozmiar() const;       //ilość elementów na liście
  Wezel* pierwszy();         //zwraca wskaz na elem pierwszy
  Wezel* ostatni();          //zwraca wskaz na elem ostatni
};   

//wsprawdza czy wpisane słowo jest palind
bool jestPal(const string &napis, Deque &Pal, Deque &Kopia);  

#endif
