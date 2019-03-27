#include "Heap.hh"


//konstruktor obiektu klasy kopiec
Heap::Heap() 
{
  lenght = 0;                 //brak elementów na kopcu
}

//destruktor obiektu klasy kopiec
Heap::~Heap() 
{
  delete []tab;
}



//zwróć indeks ojca dla danego elementu
int Heap::IndFather (const int &elem)
{
  return elem/2;
}

//zwróć indeks lewego syna 
int Heap::IndLeftSon (const int &elem)
{
  return 2*elem;
}

//zwróć indeks prawego syna 
int Heap::IndRightSon (const int &elem)
{
  return 2*elem +1;
}

//umieść wierzchołek o odpowiedniej wadze w kopcu
//zwraca lokalizację 
int Heap::insert(const int &odleg, const int &wierzch )
{
  ++lenght;                  //inkrementuj licznik elementów na kopcu
  int x, y;

  int i = lenght;

  tab[i].waga = odleg;
  tab[i].wierzcholek = wierzch;

    
  while ( i > 1 && (  (tab[IndFather(i)].waga) > odleg ) ) {

    x =  tab[i].waga;
    y =  tab[i].wierzcholek;
  
    tab[i].waga = tab[IndFather(i)].waga;
    tab[i].wierzcholek = tab[IndFather(i)].wierzcholek;

    tab[IndFather(i)].waga = x;
    tab[IndFather(i)].wierzcholek = y;


    i = IndFather(i);
  }

  return i;
}

//usuń z kopca element o najmniejszej wadze
int Heap::removeMin()
{
  if ( lenght < 1 ) {
    cout << "Kopiec jest pusty" << endl;
    return -1;                             //błąd
  }

  int max = tab[1].wierzcholek;                  //wypisz wartość wierzchołka
                                                 //o najwiekszej wadze
  tab[1].wierzcholek = tab[lenght].wierzcholek;
  tab[1].waga = tab[lenght].waga;

  //zmniejsz o 1 licznik elementów
  --lenght;

  RestoreHeap (1);                       //przywróć właściwości kopca

  return max;
}

  
  
  

//zamienia klucz dla danego elementu
void Heap::replaceKey (const int &elem, const int &odl)
{
  for ( int i=1; i <= lenght; ++i ) {
   if ( (tab[i].wierzcholek) == elem ) {
    tab[i].waga = odl;
   }
  }
}



//wyswietla zawartosc kopca
void Heap::Wyswietl()
{
  //sprawdz czy kopiec nie jest pusty
  if ( !isEmpty() ) {
      cout << "Zawartość kopca: " << endl << endl;
      for ( int i=1; i <= lenght; ++i ) {
	cout << tab[i].wierzcholek << "\t" << tab[i].waga <<  endl;
      }
      cout << endl;
    }
    else {
      cout << "Kopiec jest pusty" << endl << endl;
    }
}
 


//sprawdza czy kopiec jest pusty
bool Heap::isEmpty() 
{
  if ( lenght == 0 ) {
    return true;
  }
  else {
    return false;
  }
}


//zbuduj kopiec
void Heap::BuildHeap(const int &wym)
{
  //utwórz tablice dla kopca,
  tab = new Node [wym];
  tab[0].waga = 0;              // pierszy element jest pusty
}


//zwraca ilość elementów na kopcu
int Heap::Size ()
{
  return lenght;
}


//przywróć właściwości kopca
void Heap::RestoreHeap (int indeks)
{
  int lewySyn = IndLeftSon (indeks);       //indeks lewego syna
  int prawySyn = IndRightSon (indeks);     //indeks prawego syna

  int min, x, y;

  //sprawdź czy indeks lewego elementu nie przekracza rozmiaru kopca
  //oraz czy wartość określonego elementu jest większa niż wartość lewego syna
  if ( (lewySyn <= lenght ) && (tab[indeks].waga > tab[lewySyn].waga) ) {
    min = lewySyn;
  }
  else {
    min = indeks;
  }
  //sprawdź czy indeks prawego elementu nie przekracza rozmiaru kopca
  //oraz czy wartość określonego el jest większa niż wartość  prawego syna
  if ( (prawySyn <= lenght ) && (tab[min].waga > tab[prawySyn].waga) ) {
    min = prawySyn;
  }
  //przesuń wierzchołek w górę kopca jeżeli dany wierzchołek ma mniejszą wagę
  if ( min != indeks ) {
    x = tab[indeks].waga;
    y = tab[indeks].wierzcholek;
    tab[indeks].waga = tab[min].waga;
    tab[indeks].wierzcholek = tab[min].wierzcholek;

    tab[min].waga = x;
    tab[min].wierzcholek = y;

    RestoreHeap (min);        //wywołanie rekurencyjne dla kolejnego wierzchołka
  }
}
