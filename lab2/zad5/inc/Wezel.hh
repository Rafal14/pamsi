#ifndef WEZEL_HH
#define WEZEL_HH

/*!
 * \file
 * \brief Definicja klasy Wezel
 *
 * Plik zawiera definicje klasy węzeła listy jednokierunkowej
 * przechowujący elementy typu string
 */

//#include "Lista.hh"
#include <iostream>
#include <string>

using namespace std;

//using namespace std;

/*!
 * \brief Modeluje pojęcie węzła listy jednokierunkowej
 *
 *
 * Klasa modeluje pojęcie węzła listy jednokierunkowej
 * zawierającej elementy typu string.
 *
 */
class Wezel {

private:
  char element;                    //wartość elementu w węźle listy
  Wezel* nastepny;                      //wskaźnik na elemen następny listy 
  friend class Deque;                   //zaprzyjaźnienie klasy Lista
public:
  Wezel() { nastepny = NULL; }    //konstruktor obiektu klasy wezel

};



#endif
