#ifndef GRAPH_HH
#define GRAPH_HH

/*!
 * \file
 * \brief Definicja klasy Graf
 *
 * Plik zawiera definicje klasy metod tworzenia i dostępu do grafu
 * 
 * Program wykorzystuje listę sąsiedztwa
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
 * Klasa modeluje pojęcie listy grafu opratego na liscie sąsiedztwa
 * 
 *
 */
class Graph {

private:

  // liczba wierzchołów w grafie
  int V;

  // liczba krawędzi w grafie
  int E;          

  // wskaznik na listę krawedzi 
  Krawedz* Edges;

  // wskaznik na listę wskazników wierzcholków
  int** ListaWierz;


public:
  // konstruktor parametryczny obiektu klasy graf
  Graph(int n_V, int n_E );
  // ~Graph();
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

  // wypisuje krawędzie przylegające do wierzchołka v
  void incidentEdges( const int &v);

  // wypisuje i zwraca liczbe wszystkich krawedzi w grafie
  void edges();

  // zwraca liczbe wszystkich krawedzi w grafie
  int no_edges();

  // wczytuje dane grafu z pliku
  bool LoadGraph (string nazwa);

  //sprawdza czy graf jest pusty
  bool ifEmpty();

}; 



// Algorytm Kruskala
Lista<int> Kruskal ( Graph Gr );

// Algorytm Prima
Lista<int> Prim ( Graph Gr );





#endif
