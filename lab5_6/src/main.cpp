//plik główny programu implementcji listy jednokierunkowej
//Program umożliwia sortowanie ciągu wygenerowanych liczb losowych przez
// scalanie, szybkie sortowanie (quicksort) oraz sortownie Shella 

#include "Wezel.hh"
#include "Lista.hh"

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
typedef Lista<int> ListInt;
typedef Lista<string> ListStr;

int main()
{
  timeval t1, t2;
  double time_ms;            //zmierzony czas sortowania

  string nazwaPliku = "tablica.dat";            // nazwa pliku do zapisu
  int opcja;  
  int liczba;
  float czesc;           // czesc listy wyrażona w %, która została posortowana
  int zakres = 10000;   // zakres generowanych l. losowych
  // string liczba;     // List - lista jednokierunkowa przechowująca l. losowe
  ListInt List, Pomocnicza;    // Pomocnicza - lista pomocnicza
  // ListStr List;
  int wart;
  int *tablica = new int[100];  //tablica zawierająca wartości czasu trawnia 
                                     // sortowań
  int *TabShell = new int[zakres];    // tablica dla sortowania Shella
  int *Tab1 = new int[4];          // tablica przechowująca wartości testowe
  do {
    cout << "1.  Dodawanie pierwszego elementu do listy"
	 << " jednokierunkowej" << endl;
    cout << "2.  Usuwanie pojedynczego elementu" << endl;
    cout << "3.  Wyświetlanie zawartości" << endl;
    cout << "4.  Usuwanie wszystkich elementów"
	 << endl;
    cout << "5.  Generuj wartosc losowe" << endl;
    cout << "6.  Pokaz pierszy i ostatni element oraz rozmiar listy"
	 << endl;
    cout << "7.  Znajdz najmniejsza wartosc" << endl;
    cout << "8.  Sortuj przez scalanie ( od min do max ) " << endl;
    cout << "9.  Sortuj przez scalanie " 
	 << "liczby posortowane w odwrotnej kolejnosci" << endl;
    cout << "10. Oblicz sredni czas sortowania " << endl;
    cout << "11. Test sortowania przez scalanie ( od max do min )" 
	 << endl;
    cout << "12. Test sortowania przez scalanie ( od min do max )" 
	 << endl;
    cout << "13. Sortuj przez scalanie czesciowo posortowana"
	 << " liste" << endl;
    cout << "14. Test szybkiego sortowania ( od min do max ) " 
	 << endl;
    cout << "15. Test szybkiego sortowania ( od max do min )"
	 << endl;
    cout << "16. Szybkie sortowanie ( quicksort ) [od max do min ]"
	 << endl;
   cout << "17. Sortowanie szybkie " 
	<< "liczb posortowanych w odwrotnej kolejnosci" << endl;
   cout << "18. Sortowanie szybkie czesciowo posortowanej"
	 << " listy" << endl;
   cout << "19. Test sortowania Shella " << endl;
   cout << "20. Sortowanie Shella [od min do max]" << endl; 
   cout << "21. Sortowanie Shella " 
	<< "liczb posortowanych w odwrotnej kolejnosci" << endl;
   cout << "22. Sortowanie Shella czesciowo posortowanej"
       << " tablicy" << endl;
   cout << "0.  Koniec"
	 << endl;
    cout << "Wybierz opcję" << "\t";
    cin >> opcja;                            //wczytaj wybraną opcję
    cout << endl;

    switch(opcja)
      {
	// zakończenie działanie programu
      case 0: break;
	// dodawnie pierwszego elementu do tablicy
      case 1:
	cout << "Wpisz 1, gdy chcesz dodać element z przodu listy"
	     << endl
	     << "Wpisz 2, gdy chcesz dodać element na koniec listy"
	     << endl;  
	cin >> opcja; 	
	cout << "Wpisz element: "; 
	if (opcja == 1) {
	  cin >> liczba; 
	  List.DodajNapocz(liczba);        //dodaj liczbę na początek listy
	  cout << "Dodano element na początku listy"
	       << endl;
	}
	else if ( opcja == 2 ) {
	  cin >> liczba; 
	  List.DodajZtylu (liczba);
	  cout << "Dodano element na końcu listy"
	       << endl << endl;
	}
	else {
	  cout << "Błąd. Nieprawidłowy znak" << endl << endl;
	}
	break;
	//usuwanie pojedyczego wybranego elementu z początku listy
      case 2:
	{
	if( List.czyPusta() == true ) {
	  cout << endl << "Błąd. Lista jednokierunkowa jest pusta"
	       << endl << endl;
	}
	else {
	  cin >> opcja; 	
	  cout << "Wpisz element: "; 
	  cout << "Usunięto element z początku listy. To :  ";
	  cout << List.UsunZprzodu();
	  cout << endl << endl;
	}
	break;
	}
	//wyświetlanie zawartości listy jednokierunkowej
      case 3:
	cout << endl << endl;
	if ( List.czyPusta() == true ) {
	  cout << "Błąd. Lista jednokierunkowa jest pusta"
	       << endl << endl;
	}
	else {
	  cout << "Zawartość listy jednokierunkowej" << endl
	       << "Pierwszy element listy znajduje się na szczycie "
	       << "zestawienia" << endl;
	  List.Wyswietl();         //wyświetlenie zawrtości listy
	}
	break;
	//usuwanie wszystkich elementów z listy
      case 4: 
	if ( List.czyPusta() == true ) {
	  cout << "Błąd. Lista jednokierunkowa jest pusta"
	       << endl << endl;
	}
	else {
	  while (!List.czyPusta() ) {
	    List.UsunZprzodu();        
	                        // usunięto element z początku listy
	  }
	}
	break;

	//generuje wartości losowe i przepisuje je na listę jednokierunkową
      case 5: 
	cout << "Podaj zakres generowanych wartosci losowych: ";
	cin >> zakres;
	cout << endl;
	GenerujWartosciLosowe (zakres, List);
	break;
	
	//wypisuje wartość pierwszego i ostatniego elementu z listy
	//oraz określa długość listy
      case 6:
	if ( !List.czyPusta() ) 
	  {
	    cout << "Pierwszy element: " << List.pierwszy();
	    cout << endl;
	    cout << "Ostatni elem: " << List.ostatni();
	    cout << endl;
	    cout << "Rozmiar: " << List.rozmiar();
	    cout << endl << endl;
	  }
	break;

	// Znajduje wartość najmniejszą w liście
      case 7:
	{
	  if ( !List.czyPusta() ) {
	    cout << "Znajdz minimum: " << List.minimum();
	    cout << endl << endl;
	  }
	  break;
	}
	//Sortuje 100 losowych tablic przez scalanie
      case 8: 
	{
	  // wygeneruj 100 tablic
	  for (int i =0 ; i < 100; ++i ) {
	    GenerujWartosciLosowe (zakres, List);

	    gettimeofday(&t1, NULL);         //załączenie timera
	    List = Sortuj_scal ( List, 0 );   // sotuje od min do max
	    gettimeofday(&t2, NULL);         //wyłączenie timera
	    
	    //oblicza i wyświetla obliczony czas w ms
	    time_ms = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
	    time_ms += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
	    
	    tablica[i] = time_ms;              //zapisz zmierzoną wartość czasu
	    while(!List.czyPusta()) {List.UsunZprzodu(); }
	  }
	  ZapiszDoPliku ( nazwaPliku, tablica );
	  break;
	}

	// sortuje przez scalanie odwrotnie posortowaną listę 
      case 9:
	{
	  for (int i =0 ; i < 100; ++i ) {
	    GenerujWartosciLosowe (zakres, List);
	    List = Sortuj_scal( List, 1 );       // sortowanie od max do min

	    gettimeofday(&t1, NULL);         //załączenie timera
	    List = Sortuj_scal ( List, 0 );
	    gettimeofday(&t2, NULL);         //wyłączenie timera
	    
	    //oblicza i wyświetla obliczony czas w ms
	    time_ms = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
	    time_ms += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
	    
	    tablica[i] = time_ms;
	    while(!List.czyPusta()) {List.UsunZprzodu(); }
	  }
	  ZapiszDoPliku ( nazwaPliku, tablica );
	  break;
	}
	//Wczytuje plik z wartościami zmierzonych czasów i oblicza średnią
      case 10:
	{
	  cout << endl << "Oblicz srednia i zapisz do pliku" << endl;
	  cout << "Srednia: " << ObliczSrednia ( nazwaPliku ) << endl;
	  break;
	}
	//Testuje algorytm sortowania przez scalanie ( od największego 
	// do najmniejszego elementu )
      case 11 : 
	{
	  // test sortowania przez scalanie
	  // sortowanie od max do min
	  if ( List.czyPusta() != true ) {
	    List = Sortuj_scal( List, 1 );
	  }
	  break;
	}
	//Testuje algorytm sortowania przez scalanie ( od najmniejszego 
	// do największego elementu )
      case 12:
	{
	  // test sortowania przez scalanie 
	  // sortowanie od min do max
	  if ( List.czyPusta() != true ) {
	    List = Sortuj_scal( List, 0 );
	  }
	  break;
	}
	// Sortuje przez scalanie częściowo posortowaną listę
      case 13:
	{
	  // sortuj przez scalanie juz czesciowo posortowaną listę
	  cout << "Wpisz w %% czesc juz posortowanej listy: ";
	  cin >> czesc;     // określ wartość % posortowanej listy
	  cout << endl << endl;
	  czesc = ( czesc * zakres )/100;   //liczba elementów do posortowania
	  //------------------------------------
	
	  // wygeneruj 100 tablic
	  for (int i =0 ; i < 100; ++i ) {
	    GenerujWartosciLosowe (zakres, List);
	    //sortuj określoną część listy
	    for ( int j=0; j < czesc; ++j ) {
	      wart = List.UsunZprzodu();
	      Pomocnicza.DodajZtylu( wart );
	    }
	    Pomocnicza = Sortuj_scal ( Pomocnicza, 0 );  

	    for ( int k=0; k < zakres - czesc; ++k ) {
	      wart =  List.UsunZprzodu();
	      Pomocnicza.DodajZtylu( wart );
	    }
	  	

	    gettimeofday(&t1, NULL);   //załączenie timera
	    // sortuje całą liste
	    Pomocnicza = Sortuj_scal ( Pomocnicza, 0 );   
	    gettimeofday(&t2, NULL);         //wyłączenie timera
	    
	    //oblicza i wyświetla czas w ms
	    time_ms = (t2.tv_sec - t1.tv_sec) * 1000.0; // sec to ms
	    time_ms += (t2.tv_usec - t1.tv_usec) / 1000.0; // us to ms
	    
	    tablica[i] = time_ms;
	    while(!Pomocnicza.czyPusta()) {Pomocnicza.UsunZprzodu(); }
	  }
	  ZapiszDoPliku ( nazwaPliku, tablica );
	  
	  break;
	}
	//Testuje algorytm szybkiego sortowania
      case 14:
	{
	  // test sortowania szybkiego ( quicksort ) 
	  // sortowanie od min do max
	  if ( List.czyPusta() != true ) {
	    List =  QuickSort ( List, 0 );    
	  }
	  break;
	}
	//Testuje algorytm szybkiego sortowania
      case 15:
	{
	  // test sortowanie szybkiego ( quicksort ) 
	  // sortowanie od max do min
	  if ( List.czyPusta() != true ) {
	    List =  QuickSort ( List, 1 );    
	  }
	  break;
	}

	//Wykonuje algorytm szybkiego sortowani (quicksort)
      case 16: 
	{
	  // quicksort od min do max
	  // wygeneruj 100 tablic
	  for (int i =0 ; i < 100; ++i ) {
	    GenerujWartosciLosowe (zakres, List);

	    gettimeofday(&t1, NULL);         //załączenie timera
	    List =  QuickSort ( List, 0 );   // sotuje od min do max
	    gettimeofday(&t2, NULL);         //wyłączenie timera
	    
	    //oblicza i wyświetla czas w ms
	    time_ms = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
	    time_ms += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
	    
	    tablica[i] = time_ms;
	    while(!List.czyPusta()) {List.UsunZprzodu(); }
	  }
	  ZapiszDoPliku ( nazwaPliku, tablica );
	  break;
	} 
 
	// quicksort - sortuje od min do max liczby
	// uporządkowane w odwrotnej kolejności
      case 17:
	{
	  for (int i =0 ; i < 100; ++i ) {
	    GenerujWartosciLosowe (zakres, List);
	    List = QuickSort ( List, 1 );// sortowanie od max do min
	    
	    gettimeofday(&t1, NULL);         //załączenie timera
	    List = QuickSort ( List, 0 );
	    gettimeofday(&t2, NULL);         //wyłączenie timera
	    
	    //oblicza i wyświetla czas w ms
	    time_ms = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
	    time_ms += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
	    
	    tablica[i] = time_ms;

	    while(!List.czyPusta()) {List.UsunZprzodu(); }
	  }
	  ZapiszDoPliku ( nazwaPliku, tablica );
	  break;
	}


    case 18:
	{
	  // sortowanie szybkie juz cześciowo posortowanej listy
	  cout << "Wpisz w %% czesc juz posortowanej listy: ";
	  cin >> czesc; 
	  // cześć tablicy która ma zostać wstępnie posortowana
	  cout << endl << endl;
	  czesc = ( czesc * zakres )/100;     
	  // liczba elementów do posortowania
	  //------------------------------------
	
	  // wygeneruj 100 tablic
	  for (int i =0 ; i < 100; ++i ) {
	    GenerujWartosciLosowe (zakres,List );
	    for ( int j=0; j < czesc; ++j ) {
	      wart = List.UsunZprzodu();
	      Pomocnicza.DodajZtylu( wart );
	    }
	    // sortuje od min do max
	    Pomocnicza = QuickSort ( Pomocnicza, 0 );  

	    for ( int k=0; k < zakres - czesc; ++k ) {
	      wart =  List.UsunZprzodu();
	      Pomocnicza.DodajZtylu( wart );
	    }
	  	

	    gettimeofday(&t1, NULL);   //załączenie timera
	    // sortuje od min do max całą listę
	    Pomocnicza = QuickSort ( Pomocnicza, 0 );   
	    gettimeofday(&t2, NULL);         //wyłączenie timera
	    
	    //oblicza i wyświetla czas w ms
	    time_ms = (t2.tv_sec - t1.tv_sec) * 1000.0; // sec to ms
	    time_ms += (t2.tv_usec - t1.tv_usec) / 1000.0; // us to ms
	    
	    tablica[i] = time_ms;
	    while(!Pomocnicza.czyPusta()) {Pomocnicza.UsunZprzodu(); }
	  }
	  ZapiszDoPliku ( nazwaPliku, tablica );
	  
	  break;
	}

	// Test - sortowanie Shella
      case 19: 
	{
	  int w = 500;
	  cout << "Test -  sortowanie Shella" << endl;
	  for ( int l = 0 ; l < 4; ++l ) {
	    Tab1[l] = w;
	    w = w - 5;
	  }
	  Tab1[2] = 1000;
	  Tab1[3] = 3;
	  cout << endl << "Nieposortowana tablica" << endl;
	  for ( int p = 0 ; p < 4; ++p ) { 
	    cout << Tab1[p] << endl;
	  }

	  Tab1 = SortowanieShella ( Tab1, 4, 1);

	  // tablica posortowania
	  cout << endl << "Tablica posortowana" << endl;
	  for ( int p = 0 ; p < 4; ++p ) { 
	    cout << Tab1[p] << endl;
	  }
	  cout << endl << endl;

	  break;
	}

	// Sortowanie Shella - sortowanie liczb pseudolosowych od min do max
      case 20:
	{
	  // wygeneruj 100 tablic
	  for (int i =0 ; i < 100; ++i ) {    // ---
	    GenerujLosowe (zakres, TabShell);

	    gettimeofday(&t1, NULL);         //załączenie timera
	    TabShell = SortowanieShella(TabShell,zakres,0);   
	    gettimeofday(&t2, NULL);         //wyłączenie timera
        
	    //oblicza i wyświetla obliczony czas w ms
	    time_ms = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
	    time_ms += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
	    
	    tablica[i] = time_ms;
  	  }
	  ZapiszDoPliku ( nazwaPliku, tablica );
	  // sprawdzenie czy wartości są niemalejące

        
	  if ( SprawCzyNieMal(TabShell , zakres ) == true ) {
	    cout << endl << " Tablica jest uporzadkowana niemalejaco" 
		 << endl << endl;
	  }
	  else {
	    cout << endl << " Tablica jest uporzadkowana nierosnaco" 
		 << endl << endl;
	  }

	  break;
	}


	// sortowanie Shella - sortowanie liczb już posortowanych
      case 21:
	{
	  // wygeneruj 100 tablic
	  for (int i =0 ; i < 100; ++i ) {    // ---
	    GenerujLosowe (zakres, TabShell);
	    TabShell = SortowanieShella(TabShell,zakres,1);

	    // WyswietlTab(TabShell,zakres);       //wyświetla tablice

	    gettimeofday(&t1, NULL);         //załączenie timera
	    TabShell = SortowanieShella(TabShell,zakres,0);   
	    gettimeofday(&t2, NULL);         //wyłączenie timera
        
	    //  WyswietlTab(TabShell,zakres);     // wyświetla tablice

	    //oblicza i wyświetla czas w ms
	    time_ms = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
	    time_ms += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
	    
	    tablica[i] = time_ms;

  	  }
	  ZapiszDoPliku ( nazwaPliku, tablica );
   	  break;
	}

	// sortowanie Shella częściowo posortowanej tablicy
      case 22:
	{
	  cout << "Wpisz wartosc procentowa posortowanej tablicy: ";
	  cin >> czesc; 
	  cout << "%";
	  // cześć tablicy która ma zostać wstępnie posortowana
	  cout << endl << endl;
	  czesc = ( czesc * zakres )/100;     
	  // liczba elementów do posortowania
	  //------------------------------------
	
	  // wygeneruj 100 tablic
	  for (int i =0 ; i < 100; ++i ) {
	    GenerujLosowe (zakres, TabShell);
	    TabShell = SortowanieShella(TabShell,czesc,0);

	    // WyswietlTab(TabShell,zakres);

	    gettimeofday(&t1, NULL);   //załączenie timera
	    // sortuje od min do max całą tablicę
	    TabShell = SortowanieShella(TabShell,zakres,0);    
	    gettimeofday(&t2, NULL);         //wyłączenie timera
	    
	    //  WyswietlTab(TabShell,zakres);

	    //oblicza i wyświetla czas w ms
	    time_ms = (t2.tv_sec - t1.tv_sec) * 1000.0; // sec to ms
	    time_ms += (t2.tv_usec - t1.tv_usec) / 1000.0; // us to ms
	    
	    tablica[i] = time_ms;
	  }
	  ZapiszDoPliku ( nazwaPliku, tablica );
	  
	  break;
	}

      default:
	{
	  cout << endl << "Nieprawidłowy znak" << endl;
	  break;
	}
      }
  }while(opcja!=0);

  // usuwa z elementy z listy
  while(!List.czyPusta()) {List.UsunZprzodu(); }

  cout << "Usunieto Liste"<< endl << "----------------------"  << endl;
  delete []TabShell;           // Zwolnie pamięci
  delete []tablica;
  delete [] Tab1;

  return 0;
}
