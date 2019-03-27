// Plik główny programu implementacji grafu i algorytmu Dijkstry 
// Program umożliwia tworzenie grafu i dostęp do tego grafu 
// Pozwala na badanie czasu działania algorytmu Dijkstry
// na grafie opartym o macierz sąsiedztwa

#include "Krawedz.hh"
#include "Graph.hh"
#include "Heap.hh"
#include "Dijkstra.hh"

#include <sys/time.h>           //biblioteka dla funkcji gettimeofday()
#include <string>

using namespace std;


/*!
 *\file
 *\brief Plik glówny programu.
 *
 *Plik zawiera funkcje main programu.
 *
 */


int main()
{
  timeval t1, t2;
  double time_ms;                       //zmierzony czas sortowania

  // tablica nazw wczytywanych plików
  string NazwaPliku[100]= {
    "1.dat",
    "2.dat",
    "3.dat",
    "4.dat",
    "5.dat",
    "6.dat",
    "7.dat",
    "8.dat",
    "9.dat",
    "10.dat",
    "11.dat",
    "12.dat",
    "13.dat",
    "14.dat",
    "15.dat",
    "16.dat",
    "17.dat",
    "18.dat",
    "19.dat",
    "20.dat",
    "21.dat",
    "22.dat",
    "23.dat",
    "24.dat",
    "25.dat",
    "26.dat",
    "27.dat",
    "28.dat",
    "29.dat",
    "30.dat",
    "31.dat",
    "32.dat",
    "33.dat",
    "34.dat",
    "35.dat",
    "36.dat",
    "37.dat",
    "38.dat",
    "39.dat",
    "40.dat",
    "41.dat",
    "42.dat",
    "43.dat",
    "44.dat",
    "45.dat",
    "46.dat",
    "47.dat",
    "48.dat",
    "49.dat",
    "50.dat",
    "51.dat",
    "52.dat",
    "53.dat",
    "54.dat",
    "55.dat",
    "56.dat",
    "57.dat",
    "58.dat",
    "59.dat",
    "60.dat",
    "61.dat",
    "62.dat",
    "63.dat",
    "64.dat",
    "65.dat",
    "66.dat",
    "67.dat",
    "68.dat",
    "69.dat",
    "70.dat",
    "71.dat",
    "72.dat",
    "73.dat",
    "74.dat",
    "75.dat",
    "76.dat",
    "77.dat",
    "78.dat",
    "79.dat",
    "80.dat",
    "81.dat",
    "82.dat",
    "83.dat",
    "84.dat",
    "85.dat",
    "86.dat",
    "87.dat",
    "88.dat",
    "89.dat",
    "90.dat",
    "91.dat",
    "92.dat",
    "93.dat",
    "94.dat",
    "95.dat",
    "96.dat",
    "97.dat",
    "98.dat",
    "99.dat",
    "100.dat"
  };

  int opcja;      // licz;  

  string nazPliku;
  // obiekt typu graf
  Graph Graf(0,0);    

  int *tab_czas = new int[100];  //tablica zawierająca wartości czasu trawnia

  int *Tab_dystans=NULL;          //wskaźnik na tablicę najkrótszych ścieżek

  int l_wierz;                 // liczba wierzchołków
  int l_kraw;                  // liczba krawędzi

  do {
    cout << "1.  Wczytaj graf z pliku" << endl;
    cout << "2.  Wypisz zawartosc grafu" << endl;
    cout << "3.  Algorytm Dijkstry" << endl;
    cout << "4.  Oblicz sredni czas dzialania algorytmu " << endl;
    cout << "5.  Wyswietl tablice najkrotszych sciezek " << endl;
    cout << "6.  Zapisz wynik dzialania algorytmu Dijkstry do pliku" << endl;
    cout << "0.  Koniec"
	 << endl;
    cout << "Wybierz opcję" << "\t";
    cin >> opcja;                            //wczytaj wybraną opcję
    cout << endl;

    switch(opcja)
      {
	// zakończenie działania programu
      case 0: break;
	// wczytywanie danych z pliku do grafu
      case 1:
	cout << endl
	     << "Podaj nazwe pliku do odczytu: ";
	cin >> nazPliku;
	//wczytuje dane do grafu z pliku
	if (Graf.LoadGraph(nazPliku) == 1 ) {
	  cout << endl << "Blad odczytu pliku" << endl << endl;
	}
	break;
	// Wypisuje zawartosc grafu
      case 2:
	{
	  cout << "Liczba wierzcholkow grafu" << endl;
	  Graf.vertices();
	  cout << "Macierz sasiedztwa grafu" << endl;
	  Graf.edges();
	  cout << endl << endl;
	break;
	}

	// wyznaczanie najkrótszych ścieżkek w grafie przy pomocy algorytmu 
	// Dijkstry
	// oblicza i zapisuje czasy dzialania ww. algorytmu dla 100 losowych
	// grafów
      case 3:
	{
	  cout <<  "Wpisz liczbe wierzcholkow dla wczytywanych grafow: ";
	  cin >> l_wierz;
	  cout << endl;

	  // alokuj tablic dla najkrótszych ścieżek
	  Tab_dystans = new int [l_wierz];
	 
	  for (int i =0 ; i < 100; ++i ) {
	    nazPliku = NazwaPliku[i];
	    
	    // załaduj graf z danych pliku
	    if (Graf.LoadGraph(nazPliku) == 1 ) {
	      cout << endl << "Blad odczytu pliku" << endl << endl;
	    }

	    gettimeofday(&t1, NULL);   //załączenie timera
	    
	    // algorytm Dijkstry dla grafu nieskierowanego
	    Tab_dystans = Dijkstra ( Graf, 0 ); 
	    
	    gettimeofday(&t2, NULL);         //wyłączenie timera
	    
	    
	    //oblicza i wyświetla czas w ms
	    time_ms = (t2.tv_sec - t1.tv_sec) * 1000.0; // sec to ms
	    time_ms += (t2.tv_usec - t1.tv_usec) / 1000.0; // us to ms
	    
	    // zapisz wartości zmierzonych czasów w tablicy
	    tab_czas[i] = time_ms;
	  }
	  //zapisz wartości zmierzonych czasów do pliku Czas.dat
	  ZapiszDoPliku ( "Czas.dat" , tab_czas );
	  break;
	}

 
	//Wczytuje plik z wartościami zmierzonych czasów i oblicza średnią
      case 4:
	{
	  cout << endl << "Oblicz srednia i zapisz do pliku" << endl;
	  cout << "Srednia: " << ObliczSrednia ( "Czas.dat" ) << endl;
	  break;
	}

	//Wyświetl tablicę najkrótszych ścieżek w grafie
      case 5:
	cout << endl << "Tablica najkrotszych sciezek"
	     << endl << endl 
	     << "v" << "\t" << "dystans" << endl;
	cout << endl;
	for ( int licznik=0; licznik < l_wierz; ++licznik ) {

	  cout << licznik << "\t" << Tab_dystans[licznik]
	       << endl;
	}
	cout << endl << endl;
	break;

	//Zapisz wynik działania algorytmu Dijkstry w pliku tekstowym
      case 6: 
	//Zapisz do pliku gdy został wykonany algorytm Dijkstry
	if ( Tab_dystans != NULL ) {
	  l_wierz = Graf.no_vertices();
	  l_kraw = Graf.no_edges();
	  ZapiszSciezkiDoPliku ( "Sciezki.dat" , Tab_dystans, l_kraw, 
				  l_wierz, 0 );
	}
	else 
	  cout << "Blad. Nie mozna zapisac danych do pliku." << endl << endl;
	break;

	//Wpisano nieprawidłową wartość
      default:
	cout << endl 
	     << "Nieprawidlowa opcja. Sprobuj jeszcze raz."
	     << endl << endl;
	break;
      }
  }while(opcja!=0);

    
  //zwolnienie zaalokowanej pamięci
  delete []tab_czas;           
  if ( Tab_dystans != NULL ) {
    delete []Tab_dystans;
  }

  return 0;
}
