#ifndef QUEUE_HH
#define QUEUE_HH

/*!
 * \file
 * \brief Definicja klasy Kolejka
 *
 * Plik zawiera definicje klasy metod dostępu do kolejki
 * opartej na liście jednokierunkowej
 * przechowujący elementy określonego typu
 */


#include "Node.hh"
#include <iostream>
#include <string>

using namespace std;


/*!
 * \brief Modeluje pojęcie kolejki FIFO
 *
 *
 * Klasa modeluje pojęcie kolejki
 * zawierającej elementy typu int.
 *
 */
class Queue {

private:
  Node* head;
  Node* tail;
public:
  //bezparametryczny konstruktor 
  Queue() {head = NULL; tail = NULL; }

  //destruktor listy
  ~Queue() { while(!empty()) {dequeue();} }  
  bool empty() const;     //czy kolejka jest pusta
  void enqueue (const int &el); //dodaje elem na koniec kolejki
  void dequeue();             //usuwa pierwszy element z kolejki
  void Removefront();      //usuwa element z przodu kolejki
  void Display();     //wyświetla zawartość kolejki
};



#endif
