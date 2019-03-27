#ifndef HEAP_HH
#define HEAP_HH


/*!
 * \file
 * \brief Definicja klasy Heap
 *
 * Plik zawiera definicje klasy metod tworzenia i dostępu do kopca
 * 
 *
 */

#include <iostream>


using namespace std;


struct Node {

  int waga;             //klucz dla danego wierzchołka
  int wierzcholek;
};



/*!
 * \brief Modeluje pojęcie kopca
 *
 *
 * Klasa modeluje pojęcie kolejki priorytetowej z budowanej na kopcu
 * 
 */
class Heap {

private:

  //ilość elementów w kopcu
  int lenght;

  //wskaźnik na tablicę kopca zawierajaca wierzcholki
  Node *tab;


public:
  //konstruktor obiektu klasy kopiec
  Heap();

  //destruktor obiektu klasy kopiec
  ~Heap();


 //zbuduj kopiec
  void BuildHeap(const int &wym);

  //zwrać indeks ojca dla danego elementu
  int IndFather (const int &elem);

  //zwróć indeks lewego syna 
  int IndLeftSon (const int &elem);

  //zwróć indeks prawego syna 
  int IndRightSon (const int &elem);


  //przywróć właściwości kopca
  void RestoreHeap (int indeks);


  //umieść wierzchołek o odpowiedniej wade w kopcu
  //zwraca lokalizację 
  int insert(const int &odleg, const int &wierzch );
  
  //usuń z kopca element o najmniejszej wadze
  int removeMin();
  
  //zamienia klucz dla danego elementu
  void replaceKey (const int &elem, const int &odl);

  //wyswietla zawartosc kopca
  void Wyswietl();

  //sprawdza czy kopiec jest pusty
  bool isEmpty();

  //zwraca ilość elementów na kopcu
  int Size ();
    
};









#endif
