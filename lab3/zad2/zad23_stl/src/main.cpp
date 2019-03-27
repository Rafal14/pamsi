//plik główny programu implementacji kolejki w oparciu o biblioteke STL

#include "Kolejka.hh"
#include <iostream>
#include <sys/time.h>                // dla funkcji gettimeofday()
#include <queue>

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
  int opcja;                      //wybrana opcja
  int wart;                       //wartość elementu dodawanego
  queue<int> kolejka;           //deklaracja pojemnika typu kolejka
  string nazwaPlik;            //nazwa pliku z wartościami losowymi
  timeval t1, t2;
  double czas_wylusk;             //uzyskany czas
  do {
    cout << "1.Dodaj element do kolejki"
	 << endl;
    cout << "2.Usuń element z kolejki" << endl;
    cout << "3.Usuń wszystkie elementy ze kolejki" << endl;
    cout << "4.Wyświetl wszystkie elementy kolejki"
	 << endl;
    cout << "5.Dodawanie elementów losowych do kolejki"
	 << endl;
    cout << "0.Koniec"
	 << endl;
    cout << "Wybierz opcję" << "\t";
    cin >> opcja;
    cout << endl;
  
    switch(opcja)
      {
	// zakończenie działanie programu
      case 0: break;
	// dodawanie elementu do kolejki
      case 1:
	{
	  cout << "Podaj wartość elementu: ";
	  cin >> wart;
	  DodajElem( kolejka, wart);
	  break;
	}
	//usuwanie elementu z kolejki
      case 2:
	{
	  if ( UsunElem(kolejka) == true ) {
	    cout << "Usunięto element z kolejki" << endl;
	  }
	  break;
	}
	//usuwanie wszystkich elementów z kolejki
      case 3:
	{
	  if ( (UsunWszystkie ( kolejka )) == false ) {
	    cout << "Błąd. Kolejka jest pusta." << endl << endl;
	  } 
	  break;
	}
      //wyświetlanie zawartości kolejki
      case 4:
	{ 
	  WyswietlZawart ( kolejka ); 
	  cout << endl;
	  break;
	}
	//dodawanie elementów losowych do kolejki
      case 5:
	{
	  cout << "Podaj nazwa pliku do odczytu: ";
	  cin >> nazwaPlik;
	  // start timera
	  gettimeofday(&t1, NULL);         //załączenie timera
	  DodajLos(nazwaPlik, kolejka);    
	  gettimeofday(&t2, NULL);         //wyłączenie timera
	
	  cout << endl << endl <<  "Czas zmierzony" << endl;
	  //oblicza i wyświetla obliczony czas w ms
	  czas_wylusk = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
	  czas_wylusk += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
	  cout << czas_wylusk << " ms.\n";
	  break;
	}
      default:
	{
	  cout << endl << "Nieprawidłowy znak" << endl;
	  break;
	}
      }
  }while(opcja!=0);

  return 0;
}
