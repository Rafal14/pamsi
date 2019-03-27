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

//----------
// zwraca przeciwległy wierzchołek do wierzchołka v względem krawędzi e
int Graph::opposite( const int &v, const int &e) {
  
  // tymczasowa krawedz
  int Kr;
  int ind;
  
  for ( int i = 0; i < E; ++i ) {
    Kr = (Edges[e]).PobierzWage(); 
    if ( Kr == e ) { 
      ind = (Edges[e]).PobierzIndPierwWierz();
      if ( ind == v ) {
	return ind;
      }
      else {
	ind = (Edges[e]).PobierzIndDrugWierz();
	if ( ind == v ) {
	  return ind;
	}
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


//                   --- 
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

//-----------
// dodaje wierzchołek zawierający element o
void Graph::insertVertex(int o) {
  ++V;  // zwiększ licznik liczy wierzchołków


}

//-----
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

//-----------------
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
void Graph::incidentEdges( const int &v) {

  int waga;
  int A, B;
  cout << "Krawedzie przylegajce do wierzcholka "
       << v << " to:" << endl;
  for ( int i=0; i < E; ++i ) {
    waga = Edges[i].PobierzWage();
    A = Edges[i].PobierzIndPierwWierz();
    B = Edges[i].PobierzIndDrugWierz();
    if ( A == v ) {
      cout << endl << waga << endl;
    }
    if ( B == v ) {
      cout << endl << waga << endl;
    }
  }
  cout << endl << endl;
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
	  //	  (ListaWierz[]) = &(Edges[licznik]); 
     
          
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










































