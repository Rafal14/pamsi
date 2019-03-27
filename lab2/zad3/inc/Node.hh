#ifndef NODE_HH
#define NODE_HH

/*!
 * \file
 * \brief Definicja klasy Node
 *
 * Plik zawiera definicje klasy węzeła listy jednokierunkowej
 * przechowujący elementy typu string
 */

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
class Node {

private:
  int element;                    //wartość elementu w węźle kolejki
  Node* next;                //wskaźnik na elemen następny kolejki 
  friend class Queue;               //zaprzyjaźnienie klasy 
public:
  Node() { next = NULL; }    //konstruktor obiektu klasy wezel

};



#endif
