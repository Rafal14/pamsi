#ifndef GRAPH_HH
#define GRAPH_HH

/*!
 * \file
 * \brief Definicja klasy Graf
 *
 * Plik zawiera definicje klasy metod tworzenia i dostępu do grafu
 * 
 * Program wykorzystuje macierz sąsiędztwa
 *
 */


#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>


using namespace std;

#define INT_MAX 2147483647

/*!
 * \brief Modeluje pojęcie grafu
 *
 *
 * Klasa modeluje pojęcie listy grafu
 * 
 *
 */
class Graph {

private:

  // liczba wierzchołów w grafie
  int V;

  // liczba krawędzi w grafie
  int E;          

  // lista krawedzi 
  Krawedz* Edges;

  // wskaźnik na wskaźnik tablicy alokowanej dynamicznie
  // przechowującej wartości wag krawędzi grafu
  Krawedz*** macierz;


public:
  // konstruktor parametryczny obiektu klasy graf
  Graph(int n_V, int n_E );

  // tablica dwóch końcowych wierzchołów połączonych przez krawędź e
  int* endVertices(const int &e);
  
  // zwraca przeciwległy wierzchołek do wierzchołka v względem krawędzi e
  int opposite( const int &v, const int &e);
  
  // zwraca wage krawedzi gdy wierzchołki v i w są sąsiednie
  int areAdjacent( const int &v,  const int &w);
  
  // zamienia miejscami wierzchołki v i w  
  void replaceVert( const int &v, const int &w);
  
  // dodaje wierzchołek zawierający element o
  void insertVertex(int o);

  // usuwa i zwraca wierzcholek 
  int removeVertex( const int &v);

  // wypisuje i zwraca wszystkie wierzchołki w grafie
  void vertices();

  // zwraca wszystkie wierzchołki w grafie
  int no_vertices();



  //------------------
 // zastępuje element na krawędzi e na x
  void replaceByEdge( const int &e, const int &x);

  // dodaje krawędź (v,w) zawierającą element o
  void insertEdge( const int &v, const int &w,int o);

 // usuwa krawędź e
  int removeEdge( const int &e);

  // zwraca tablicę krawędzi przylegających do wierzchołka v
  int* incidentEdges( const int &v);

  // wypisuje i zwraca liczbe wszystkich krawedzi w grafie
  void edges();

  // zwraca liczbe wszystkich krawedzi w grafie
  int no_edges();

  // wczytuje dane grafu z pliku
  bool LoadGraph (string nazwa);

  //sprawdza czy graf jest pusty
  bool ifEmpty();

}; 



// zapisuje wartosci czasow trwania do pliku
bool ZapiszDoPliku (string nazwa, int *tab );



// oblicza srednia
int ObliczSrednia ( string nazwa ) ;

#endif
