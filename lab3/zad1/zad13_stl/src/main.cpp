//plik główny programu implementacji stosu w oparciu o biblioteke STL

#include "Stos.hh"
#include <iostream>
#include <sys/time.h>                // dla funkcji gettimeofday()
#include <stack>

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
  unsigned int liczba;              //liczba wpisywana na stos
  int wart;                       //wartość elementu dodawanego
  stack<int> stos;                //deklaracja pojemnika typu stos
  string nazwaPlik;               //nazwa pliku z wartościami losowymi
  timeval t1, t2;
  double czas_wylusk;             //uzyskany czas
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
	cout << endl << "Podaj pozycję elementu na stosie. "
	     << "Wpisz '0' by dodać element na szczyt stosu"
	     << endl << "\t";
	cin >> liczba;
	cout << "Podaj wartość elementu: ";
	cin >> wart;
	if ( DodajElem( stos, liczba, wart) == true ) {
	  cout << endl << "Dodano element na stos" << endl;
	}
	break;
	//usuwanie elementu z stosu
      case 2:
	cout << "Podaj element, który chcesz usunąć"
	     << endl;
	cin >> liczba;
	if ( UsunElem(stos, liczba) == false ) {
	  cout << "Nie można usunąć elementu ze stosu." << endl;
	}
	break;
	//usuwanie wszystkich elementów z stosu
      case 3:
	if ( (UsunWszystkie ( stos )) == false ) {
	  cout << "Błąd. Stos jest pusty." << endl << endl;
	} 
	break;
      //wyświetlanie zawartości stos
      case 4: 
	WyswietlZawart ( stos ); //usuwa wybrany element ze stosu
	cout << endl;
	break;
	//dodawanie elementów losowych na stos
      case 5:
	cout << "Podaj nazwa pliku do odczytu: ";
	cin >> nazwaPlik;
	// start timera
	gettimeofday(&t1, NULL);         //załączenie timera
	DodajLos(nazwaPlik, stos);       
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
