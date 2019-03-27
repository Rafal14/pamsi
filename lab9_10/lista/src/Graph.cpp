#include "Krawedz.hh"
#include "Graph.hh"



//konstruktor obiektu typu graf
Graph::Graph(int n_V, int n_E )
{ 
  V = n_V; 
  E = n_E;
}


// zwraca tablice dwóch końcowych wierzchołów połączonych przez krawędź e
int* Graph::endVertices(const int &e) {

  int* Wierz = new int [2];

  Wierz[0] = (Edges[e]).PobierzIndPierwWierz(); //wpisuje indeks 1. wierz
  Wierz[1] = (Edges[e]).PobierzIndDrugWierz();  //wpisuje indeks 2. wierz
 
  return Wierz;
}


// zwraca przeciwległy wierzchołek do wierzchołka v względem krawędzi e
int Graph::opposite( const int &v, const int &e) {
  
  // tymczasowy indeks wierz
   int Kr;
   int A, B;
  for ( int i = 0; i < E; ++i ) {
    Kr = (Edges[i]).PobierzWage(); 
    if ( Kr == e ) { 
  
      A = (Edges[i]).PobierzIndPierwWierz();
      B = (Edges[i]).PobierzIndDrugWierz();
      if ( A == v ) {
	return B;
      }
      if ( B == v ) {
	return A;
      }
    }
  }
  return -1;       //blad
}

// zwraca 'prawda' gdy wierzchołki v i w są sąsiednie
int Graph::areAdjacent( const int &v,  const int &w) {
  
  int waga;
  int A;
  int B;
  //przejrzyj liste krawedzi
  for ( int i=0; i < E; ++i ) {
    A = (Edges[i]).PobierzIndPierwWierz();
    B = (Edges[i]).PobierzIndDrugWierz();
    waga = (Edges[i]).PobierzWage();
    if ( A == v  ||  B == w ) {
      return waga;
    }
  }
  return -1;
}



// zamienia miejscami wierzchołki v i w  
void Graph::replaceVert( const int &v, const int &w) {
 
  int A, B;
  for ( int i=0; i < E; ++i ) {
    A = (Edges[i]).PobierzIndPierwWierz();
    B = (Edges[i]).PobierzIndDrugWierz();
    if ( A == v  && B == w ) {
      (Edges[i]).WpiszIndPierwWierz (B);
      (Edges[i]).WpiszIndDrugWierz (A);
    }
  }
}


// dodaje wierzchołek zawierający element o
void Graph::insertVertex(int o) {
  ++V;  // zwiększ licznik liczy wierzchołków


}


// usuwa wierzchołek oraz przylegające do niego krawędzie
int Graph::removeVertex( const int &v) {
  int A, B;

  //usun krawedzie (null) z macierzy
  for ( int i=0; i < E; ++i ) {
    A = (Edges[i]).PobierzIndPierwWierz();
    B = (Edges[i]).PobierzIndDrugWierz();
    if ( A == v ) {
      (Edges[i]).WpiszIndPierwWierz (-1);
      (Edges[i]).WpiszIndDrugWierz (-1);
      (Edges[i]).WpiszWageKraw (0);
    }
    else if ( B == v ) {
      (Edges[i]).WpiszIndPierwWierz (-1);
      (Edges[i]).WpiszIndDrugWierz (-1);
      (Edges[i]).WpiszWageKraw (0);
    }
  }

  // 
  --V;      // dekrementuj licznik
  return v;
}



// wypisuje wszystkie wierzchołki w grafie ( wraz z krawedziami )
void Graph::vertices() {
 
  cout << "Wierzcholki w grafie" << endl;
  for ( int i= 0; i < E; ++i ) {
    cout << (Edges[i]).PobierzIndPierwWierz() << "\t"
	 << (Edges[i]).PobierzIndDrugWierz() <<  "\t"
	 << (Edges[i]).PobierzWage();
    cout << endl;
  }
}

// zwraca ilosc wierzcholkow
int Graph::no_vertices() {
  return V;
}

// zastępuje element na krawędzi e na x
void Graph::replaceByEdge( const int &e, const int &x)
{
  int Waga;
  // przeszukanie listy krawedzi
  for (int i=0; i < E; ++i ) {
    Waga = Edges[i].PobierzWage();
    if ( Waga == e ) { 
      Edges[i].WpiszWageKraw( x );
    }
  }
}


// dodaje krawędź (v,w) zawierającą element o
void Graph::insertEdge( const int &v, const int &w,int o)
{
  ++E;
  Krawedz* Ed = new Krawedz [E];              // tymczasowa tablica 

  int wag, A, B;

  for ( int i=0; i < E; ++i ) {
    A = Edges[i].PobierzIndPierwWierz();
    B = Edges[i].PobierzIndDrugWierz();
    wag =  Edges[i].PobierzWage();

    Ed[i].WpiszWageKraw( wag );
    Ed[i].WpiszIndPierwWierz( A );
    Ed[i].WpiszIndDrugWierz( B );
  }
  Edges = Ed; 

}


// usuwa krawędź e
int Graph::removeEdge( const int &e)
{ 
  return Edges[e].PobierzWage();
}
 

 // wypisuje krawędzie przylegające do wierzchołka v
int* Graph::incidentEdges( const int &v) {

  int *Tablica = new int [V];
  
  int waga;
  int A, B;

  int licz = 0;
  
  for ( int j=0; j < V; ++j ) {
    Tablica[j] = 0;
  }
 
  for ( int i=0; i < E; ++i ) {
    waga = Edges[i].PobierzWage();
    A = Edges[i].PobierzIndPierwWierz();
    B = Edges[i].PobierzIndDrugWierz();
   
    if ( A == v ) {
      Tablica[licz] = waga;
      ++licz;
    }

    if ( B == v ) {
      Tablica[licz] = waga;
      ++licz;
    }
  }
  return Tablica;
}



// wypisuje wszystkie krawędzie 
void Graph::edges()
{ 
  cout << endl << endl
       << "Krawedzie grafu: " << endl;
  for (int k=0; k < E; ++k) {
    cout << (Edges[k]).PobierzWage()
	 << endl;
  }
  cout << endl; 
}


// zwraca liczbe krawedzi
int Graph::no_edges() {
  return E;
}


// sprawdza czy graf jest pusty
bool Graph::ifEmpty() {
  if ( V == 0 ) {
    return true;
  }
  else
    return false;
}


// wczytuje dane do grafu z pliku
bool Graph::LoadGraph (string nazwa) {
  ifstream PlikWej;                       //deklaracja pliku do zapisu
  int no_V;                              // liczba wierzcholkow grafu
  int no_E;                              //liczba krawedzi grafu    
  int licznik =0;
  int liczba;
  PlikWej.open( nazwa, fstream::in );     //otwórz strumień do odczytu danych
  PlikWej >> no_V;
  PlikWej >> no_E;
  
  if ( V == 0 && E == 0 ) {
  
    //zainicjowanie listy krawedzi ( listy obiektów typu krawedz )
    Edges = new Krawedz [no_E];

    //zainicjowanie listy wierzchołów
    ListaWierz = new int *[no_V];
  }

   
  V = no_V;
  E = no_E;


  // wczytywanie danych do listy
  for ( int w = 0 ; w < no_V; ++w ) {
    for ( int k = w ; k < no_V; ++k ) {
      if ( k!=w ) {
	if ( licznik < no_E ) {  
	  PlikWej >> liczba;
	  (Edges[licznik]).WpiszWageKraw ( liczba );  
	  (Edges[licznik]).WpiszIndPierwWierz (w);
	  (Edges[licznik]).WpiszIndDrugWierz (k);
     
          
	  ++licznik;
	  if(PlikWej.fail() )
	    {
	      PlikWej.close(); //jeśli nie udało się odczytac, zamknij strumień
	      return 1;
	    }
	}
      }
    }
  }
  PlikWej.close(); 
  
  return 0;
}






//----------------------------------------------------------------------


/*

 */

// zapisuje wartosci czasow trwania do pliku
bool ZapiszDoPliku (string nazwa, int *tab )
{
  ofstream PlikWyj;                  //deklaracja pliku do zapisu    
  PlikWyj.open( nazwa, fstream::out );       //otwórz strumień do zapisu
  for ( int i = 0 ; i < 100; ++i ) { 
    PlikWyj << tab[i] << endl;
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

// oblicza srednia
int ObliczSrednia ( string nazwa ) 
{
  int *t = new int[100];
  int elem =0 ;
  ifstream PlikWej;                  //deklaracja pliku do zapisu    
  PlikWej.open( nazwa, fstream::in );       //otwórz strumień do zapisu
  for (int i=0; !PlikWej.eof(); ++i ) { 
    PlikWej >> t[i];
  }
  PlikWej.close();
  for ( int j=0; j < 100; ++j) {
    elem += t[j];
  }
  elem = elem /100;
  return elem;
}
