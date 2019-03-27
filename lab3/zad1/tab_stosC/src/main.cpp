//plik główny programu implementcji stosu w oparciu o tablice

#include "Stos.hh"
#include <iostream>
#include <sys/time.h>                // dla funkcji gettimeofday()

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
 string nazwaPlik;            //nazwa pliku z wartościami losowymi
  Stos Tablica(1);               //jednoelementowa tablica
  timeval t1, t2;
  double czas_wylusk;            //uzyskany czas
  do {
    cout << "1.Dodaj element do stosu"
	 << endl;
    cout << "2.Usuń element ze stosu" << endl;
    cout << "3.Usuń wszystkie elementy ze stosu" << endl;
    cout << "4.Wyświetl wszystkie elementy stosu"
	 << endl;
    cout << "5.Dodawanie elementów losowych na stos"
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
	// dodawanie elementu do stosu
      case 1:
	cout << "Podaj wartość elementu: ";
	cin >> wart;
	Tablica.DodajElem ( wart );
	cout << "Dodano element na stos" << endl << endl;
	break;
	//usuwanie elementu z stosu
      case 2:
	cout << "Usuwanie elementu ze stosu" << endl;
        cout << "Element usunięty to " << Tablica.UsunElem()
	     << endl << endl;
	break;
	//usuwanie wszystkich elementów z stosu
      case 3:
	if ( Tablica.czyPusty() == true ) {
	  cout << "Nie można usunąć elementów" << endl
	       << "Stos jest pusty" << endl;
	}
	else {
	  while (!Tablica.czyPusty() ) {
	    Tablica.UsunElem();
	  }
	  cout << "Usunięto wszystkie elementy ze stosu" << endl;
	}
	break;
      //wyświetlanie zawartości stos
      case 4: 
	cout << "Zawartość stosu" << endl;
	cout << "Szczyt stosu znajduje się na początku zestawienia"
	     << endl;
	Tablica.WyswietlZawart();
	cout << endl;
	break;
	//dodawanie elementów losowych na stos
      case 5: 
	cout << "Podaj nazwa pliku do odczytu: ";
	cin >> nazwaPlik;
	// start timera
	gettimeofday(&t1, NULL);         //załączenie timera
	DodajLos( nazwaPlik,Tablica );      //wykownywanie funkcji
	gettimeofday(&t2, NULL);         //wyłączenie timera
	
	cout << endl << endl <<  "Czas zmierzony" << endl;
	//oblicza i wyświetla obliczony czas w ms
	czas_wylusk = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
	czas_wylusk += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
	cout << czas_wylusk << " ms.\n";  
	break;
      default:
	{
	cout << endl << "Nieprawidłowy znak" << endl;
	break;
	}
      }
  }while(opcja!=0);

  return 0;
}
