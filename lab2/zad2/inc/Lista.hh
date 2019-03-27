#ifndef LISTA_HH
#define LISTA_HH

/*!
 * \file
 * \brief Definicja klasy Lista
 *
 * Plik zawiera definicje klasy metod dostępu do listy jednokierunkowej
 * przechowujący elementy określonego typu
 */


#include "Wezel.hh"
#include <iostream>
#include <string>

using namespace std;


/*!
 * \brief Modeluje pojęcie listy jednokierunkowej
 *
 *
 * Klasa modeluje pojęcie listy jednokierunkowej
 * zawierającej elementy typu string.
 *
 */
class Lista {

private:
  Wezel* glowa;         //wskaźnik na głowe listy jednokierunkowej
  Wezel* ogon;          //wskaźnik na ostatni element listy

public:
  //bezparametryczny konstruktor klasy 
  Lista() {glowa = NULL; ogon = NULL; }

  //destruktor listy
  ~Lista() { while(!czyPusta()) {UsunZprzodu();}}  
  bool czyPusta() const;     //czy lista jednokierunkowa jest pusta
  void DodajNapocz(const int &el);    //dodaje elem z przodu listy
  void UsunZprzodu();      //usuwa element z przodu listy jednokier
  void DodajZtylu (const int &el);   //dodaje z tylu element     
  void Wyswietl();     //wyświetla zawartość listy jednokierunkowej
};



#endif
