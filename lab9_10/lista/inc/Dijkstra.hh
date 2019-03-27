#ifndef DIJKSTRA_HH
#define DIJKSTRA_HH


/*!
 * \file
 * \brief Definicja algorytmu Dijkstry
 *
 *
 * Funkcja wyznacza najkrótsze możliwe ścieżki w grafie
 *
 * Funkcja zwraca tablice ścieżek 
 *
 */




//algorytm Dijkstra
int* Dijkstra ( Graph Gr, const int &w_start );


// zapisuje do pliku tablicę najkrótszych ścieżek
bool ZapiszSciezkiDoPliku ( string nazwa, int *tab, int krawedzie, 
			    int wierzcholki, int wierz_start );


#endif
