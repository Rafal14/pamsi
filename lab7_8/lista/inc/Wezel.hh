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

using namespace std;

/*!
 * \brief Modeluje pojęcie węzła listy jednokierunkowej
 *
 *
 * Klasa modeluje pojęcie węzła listy jednokierunkowej
 * zawierającej elementy.
 *
 */
template <typename T>
class Wezel {
  //private:
public:
  T element;         // element wezla , waga krawedzi
  T wierz_v;
  T wierz_w;
  Wezel<T>* nastepny;    //wskaźnik na elemen następny listy 

  //  friend class Lista<T>;
  //public:
  Wezel() {  nastepny = NULL; }

};



#endif


