#include "Krawedz.hh"
#include "Heap.hh"
#include "Graph.hh"



 
//algorytm Dijkstra - zwraca tablicę najkrótszych scieżek do wierzchołków
int* Dijkstra ( Graph Gr, const int &w_start )
{
  int A, B;                         //wierzcholek
  int edge;                      // krawedz

  int odleglosc;
  
  int roz = Gr.no_vertices();         //ilość wierzchołków w grafie
  Heap Kol;                          //puste drzewo

  Kol.BuildHeap(roz+1);              //zbuduj pusty kopiec o wielkości roz+1
                                     //pierwszy element tablicy jest pusty

  //utwórz listę odległości od wierzchołka początkowego
  int *dystans = new int [roz];

  //utwórz tablice krawedzi przylegających do wierzchołka
  int *Tab = new int [roz];
  
  // każdemu wierzchołkowi przydziel odpowiedni dystans
  for ( int v=0; v < roz; ++v ) {
    
    //ustaw wierzchołek startowy zgodnie z argumentem funkcji algorytmu Dijkstry
    if ( v == w_start ) {
      dystans[v] = 0;
    }
    else {
      dystans[v] = INT_MAX;
    }

    Kol.insert( dystans[v], v );  
  }
  
  //dopóki kolejka nie jest pusta 
  while ( !Kol.isEmpty() ) {

    //usuń wierzcholek o najmniejszej odleglości
    A = Kol.removeMin(); 
    
    //zwróć krawędzie przylegające do wierzchołka A
    Tab = Gr.incidentEdges( A );
 
    //dla każdego wierzchołka oblicz najkrótszą ścieżkę od wierzchołka pocz.
    for (int i=0; i < (roz-1) ; ++i) {
      if ( Tab[i] != 0 ) {
	edge = Tab[i];

	//zwróć wierzchołek sąsiedni do A względem krawędzi edge
      	B = Gr.opposite (A, edge);         
	odleglosc = dystans[A] + edge ;
    
	//sprawdź czy ścieżka do wierzchołka jest krótsza od obecnej wagi
	if ( odleglosc < dystans[B] ) {
	    dystans[B] = odleglosc;
	    //zaktualizuj wartość najkrótszej ścieżki do wierzchołka B
	    Kol.replaceKey ( B , odleglosc);  
	}
      }
    }
  }

  //zwolnij zaalokowana pamięć na krawędzie incydentne
  delete []Tab;
 
  return dystans;          //zwróć tablicę najkrótszych ścieżek
}





// zapisuje do pliku tablicę najkrótszych ścieżek
bool ZapiszSciezkiDoPliku ( string nazwa, int *tab, int krawedzie, 
			    int wierzcholki, int wierz_start )
{
  ofstream PlikWyj;                          //deklaracja pliku do zapisu   
  PlikWyj.open( nazwa, fstream::out );       //otwórz strumień do zapisu

  //wypisz liczbę krawędzi, wierzchołków i indeks wierzchołka startowego
  PlikWyj << krawedzie << "\t" << wierzcholki << "\t" << wierz_start << endl;

  for ( int i = 0 ; i < wierzcholki; ++i ) { 
    PlikWyj << wierz_start << "\t" << i << "\t" << tab[i] << endl;
  }
  if(PlikWyj.fail() )
    {
      PlikWyj.close(); //jeśli udało się zapisać, zamknij strumień
      cout << "Błąd. Nieudało się zapisać";
      return 1;
    }
  else {
    PlikWyj.close();
  }
  return 0;
}
