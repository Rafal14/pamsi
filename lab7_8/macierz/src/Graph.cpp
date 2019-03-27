#include "Lista.hh"
#include "Krawedz.hh"
#include "Zbior.hh"
#include "Graph.hh"



//konstruktor obiektu typu graf
Graph::Graph(int n_V, int n_E )
{ 
  V = n_V; 
  E = n_E;
}

//Graph::~Graph() {
  // delete []Edges;
  /*  for ( int i=0; i < V; ++i ) {
    for ( int j =0; i < V; ++i ) {
      delete [] macierz[i][j];
    }
  }
  for ( int k=0; k < V; ++k ) {
    for ( int l =0; l < V; ++l ) {
      delete [] macierz[k][l];
    }
  }
  delete []macierz;
  }*/

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
      if ( (*macierz[v][i]).PobierzWage() == e ) {
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


//                 ---
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


// dodaje wierzchołek zawierający element o
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
         //            ---???

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
 

 // wypisuje krawędzie przylegające do wierzchołka v
void Graph::incidentEdges( const int &v) {

  cout << "Krawedzie przylegajce do wierzcholka "
       << v << " to:" << endl;
  for ( int i=0; i < V; ++i ) {
    if ( macierz[v][i] != NULL ) { 
      //krawedzie przylegajace do wierzcholka v

      cout << (*macierz[v][i]).PobierzWage() << endl;
    }
  }
  cout << endl << endl;
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









//----------------------------------------------------------------------

//algorytm Kruskala
Lista<int> Kruskal ( Graph Gr )
{
  int A, B;                      //wierzcholki
  int edge;                      // krawedz

  int l_kraw = Gr.no_edges();

  int roz = Gr.no_vertices();
  Lista<int> Tree;                    //puste drzewo
  Lista<int> PosortKr;           //lista posortowanych krawedzi
  
  int *Tab;

  Zbior Klas(roz);

  //utworzenie listy wierzchołków
  for ( int x=0; x < roz; ++x ) {
    Klas.Make_set (x);
  }
 
  //posortuj krawedzie od najmniejszej do najwiekszej wagi
  for ( int i=0; i < l_kraw; ++i ) {
    Tab = Gr.endVertices(i);
    edge = Gr.removeEdge(i);
    A = Tab[0];
    B = Tab[1];
    PosortKr.DodajElem(edge, A, B);     //wpisz do kolejki priorytetowej
  }
  delete []Tab;

  for ( int j=0; j < l_kraw; ++j ) {
    edge = PosortKr.UsunZprzodu(A,B);
    int find_A =  Klas.Find_set(A);            //
    int find_B =  Klas.Find_set(B);
    // czy wierzchołki A i B należą do tego samego drzewa
    if ( find_A != find_B ) {
      Tree.DodajNapocz ( edge, A , B );       //krawedz do drzewa
      Klas.Union(find_A, find_B);           //połącz dwa  drzewa
    }
  }
  //wyswietl drzewo
  //cout << endl << endl;
  //Tree.Wyswietl();
  return Tree;
}







//algorytm Prima-Jarnika
Lista<int> Prim ( Graph Gr )
{
  int A, B;                      //wierzcholki
  int edge;                      // krawedz

  int roz = Gr.no_vertices();
  Lista<int> Tree;                    //puste drzewo
  Lista<int> PosortKr;           //lista posortowanych krawedzi

  //utwórz listę odwiedzanych wierzchołków
  int *odwiedzane = new int [roz];

  // wpisanie inf do tablicy odwiedzanych wierzchołków
  for ( int i=0; i < roz; ++i ) {
    odwiedzane[i] = INT_MAX;
  }

  //wybranie dowolnego wierzcholka poczatkowego jako pierwszego
  A = 0;
  odwiedzane[A] = 0;              //wierzchołek został odwiedzony
 

  for ( int j=1; j < roz; ++j) {
    for ( int k=0; k < roz; ++k) {
      if ( Gr.areAdjacent( j, k) != -1 ) {
	edge = Gr.areAdjacent( j, k);
	odwiedzane[k] = INT_MAX;
	//dodanie do kolejki priorytetowej nieodwiedzonej krawedzi
	PosortKr.DodajElem(edge, j, k);   
      }
    }
   
    // pobierz krawedz z kolejki priorytetowej
   
    do {
      edge = PosortKr.UsunZprzodu(A,B); //usun krawedz z kolejki 
    } while (odwiedzane[A] < INT_MAX);

    Tree.DodajNapocz ( edge, A , B );   //dodaj krawedz do drzewa
    odwiedzane[B] = 0;            //wierzcholek zostal odwiedzony
    // A = B;
  }
  

  //zwolnij pamieć tablicy odwiedzanych wierzchołków
  delete []odwiedzane;
 
  return Tree;
}









































































