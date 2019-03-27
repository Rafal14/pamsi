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
  
  // tymczasowa krawedz
  Krawedz Kr;  
  for ( int i = 0; i < E; ++i ) {
    if ( macierz[v][i] != NULL ) { 
      Kr = *macierz[v][i];
      if ( ((*macierz[v][i]).PobierzWage()) == e ) {
	return i;
      }
    }
  }
  return -1;
}

// zwraca 'prawda' gdy wierzchołki v i w są sąsiednie
int Graph::areAdjacent( const int &v,  const int &w) {
  
  int waga;
  //wierzchołki nie są incydentne
  if ( macierz[v][w] == NULL ) {
    return -1;
  }
  //wierzchołki v i w są incydentne
  waga = (*macierz[v][w]).PobierzWage();
  return waga;
}



// zamienia miejscami wierzchołki v i w  
void Graph::replaceVert( const int &v, const int &w) {
  int kr1, kr2;
  //jezeli maja wspolna krawedzi
  for ( int i=0; i < V; ++i) {
    if ( macierz[v][i] != NULL )  { 
      kr1 = (*macierz[v][i]).PobierzWage();
    }
    if ( macierz[w][i] != NULL )  { 
      kr2 = (*macierz[w][i]).PobierzWage();
    }
    if ( (macierz[v][i] != NULL)   &&  (macierz[w][i] != NULL) ) {
      (*macierz[v][i]).WpiszWageKraw(kr2); 
      (*macierz[w][i]).WpiszWageKraw(kr1);
    } 
    if ( (macierz[v][i] == NULL)   &&  (macierz[w][i] != NULL) ) {
      if ( w != i  ) {
	macierz[v][i] = macierz[w][i];
	(*macierz[w][i]).WpiszIndPierwWierz(v);
	macierz[w][i] = NULL;
      }
    }
    if ( (macierz[v][i] != NULL)   &&  (macierz[w][i] == NULL) ) {
      if ( v != i ) {
	macierz[w][i] = macierz[v][i];
	(*macierz[w][i]).WpiszIndPierwWierz(w);
	macierz[v][i] = NULL;
      }
    }
  }
}


//dodaje wierzchołek zawierający element o
void Graph::insertVertex(int o) {
  ++V;  // zwiększ licznik liczy wierzchołków

  // utworzenie tymczasowej macierzy
  Krawedz*** mac = new Krawedz **[V];
  for(int i = 0; i<V; ++i) {
    mac[i] = new Krawedz *[V];
  }
  
  //przepisanie zawartosci poprzedniej macierzy do nowej
  for (int j; j < (V-1); ++j ) {
    for (int k; k < (V-1); ++k ) {
      mac[j][k] = macierz[j][k];
    }
  }
}


// usuwa wierzchołek oraz przylegające do niego krawędzie
int Graph::removeVertex( const int &v) {
 
  //usun krawedzie (null) z macierzy
  for ( int i=0; i < V; ++i ) {
    macierz[v][i] = NULL;
    macierz[i][v] = NULL;
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

  (*macierz[v][w]).WpiszIndPierwWierz( v );
  (*macierz[v][w]).WpiszIndDrugWierz( w );
  (*macierz[v][w]).WpiszWageKraw ( o );

  ++E;                       //inkrementuj licznik krawędzi
}


// usuwa krawędź e
int Graph::removeEdge( const int &e)
{
  int waga =  Edges[e].PobierzWage();
  return waga;
}
 

// zwraca tablice krawędzi przylegających do wierzchołka v 
int* Graph::incidentEdges( const int &v)
{
  int *Tablica = new int [V];
  int licznik = 0; 

  //wypelenienie tablicy zerami
  for ( int j=0; j < V; ++j ) {
    Tablica[j] = 0;
  } 


  for ( int i=0; i < V; ++i ) {
    if ( (macierz[v][i] != NULL) && (v != i ) ) { 
      //krawedzie przylegajace do wierzcholka v
      Tablica[licznik] = (*macierz[v][i]).PobierzWage();
      ++licznik;
    }
  }
  return Tablica;
}


// wypisuje wszystkie krawędzie  i macierz sasiedztwa grafu
void Graph::edges()
{
  Krawedz Kr;
  for(int i = 0; i<V; ++i) {
    for (int j=0; j<V; ++j) {
  
      if ( macierz[i][j] == NULL ) {
	cout << "0"  << "\t";
      }
      else {
	Kr = *macierz[i][j];
	cout << Kr.PobierzWage() << "\t";
      }
    }
    cout << endl << endl;
  } 
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
    // zainicjowanie macierzy sasiedztwa
    macierz = new Krawedz **[no_V];
    for(int i = 0; i<no_V; ++i) {
      macierz[i] = new Krawedz *[no_V];
    }
    //zainicjowanie listy krawedzi ( listy obiektów typu krawedz )
    Edges = new Krawedz [no_E];
  }
  // wypelnie macierzy wskaznikami na puste elem
  for(int y = 0; y < no_V; ++y) {
    for(int z = 0; z < no_V; ++z) {
      (macierz[y][z]) = NULL;
    }
  }
   
  V = no_V;
  E = no_E;


  // wczytywanie danych do macierzy
  for ( int w = 0 ; w < no_V; ++w ) {
    for ( int k = w ; k < no_V; ++k ) {
      if ( k!=w ) {
	if ( licznik < no_E ) {  
	  PlikWej >> liczba;
	  (Edges[licznik]).WpiszWageKraw ( liczba );  
	  (Edges[licznik]).WpiszIndPierwWierz (w);
	  (Edges[licznik]).WpiszIndDrugWierz (k);
	  (macierz[w][k]) = &(Edges[licznik]); //.WpiszWageKraw (liczba);
	  (macierz[k][w]) = &(Edges[licznik]);

       
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

// oblicza średnią
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
