//plik główny programu implementacji kolejki deque

#include "Wezel.hh"
#include "Deque.hh"
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
  int opcja;  
  char znak;     
  string slowo;   
  int liczba;
  Deque List;
  Deque Kop;
  do {
    cout << "1.Dodawanie pierwszego elementu do kolejki deque"
	 << endl;
    cout << "2.Usuwanie pojedynczego elementu" << endl;
    cout << "3.Wyświetlanie zawartości" << endl;
    cout << "4.Usuwanie wszystkich elementów"
	 << endl;
    cout << "5.Sprawdz czy słowo jest palindromem" << endl;
    cout << "0.Koniec"
	 << endl;
    cout << "Wybierz opcję" << "\t";
    cin >> opcja;
    cout << endl;

    switch(opcja)
      {
	// zakończenie działanie programu
      case 0: break;
	// dodawnie pierwszego elementu do kolejki
      case 1:
	cout << "Wpisz 1, gdy chcesz dodać element z przodu kolejki"
	     << endl
	     << "Wpisz 2, gdy chcesz dodać element na koniec "
	     << "kolejki"
	     << endl;  
	cin >> liczba; 	
	cout << "Wpisz element: "; 
	if (liczba == 1) {
	  cin >> znak; 
	  List.DodajNapocz(znak);   //dodaj znak z przodu listy
	  cout << "Dodano element na początek kolejki"
	       << endl;
	}
	else if ( liczba == 2 ) {
	  cin >> znak; 
	  List.DodajZtylu (znak);
	  cout << "Dodano element na końcu kolejki"
	       << endl << endl;
	}
	else {
	  cout << "Błąd. Nieprawidłowy znak" << endl << endl;
	}
	break;
	//usuwanie pojedyczego wybranego elementu z kolejki
      case 2:
	if( List.czyPusta() == true ) {
	  cout << endl << "Błąd. Kolejka jest pusta"
	       << endl << endl;
	}
	else {
	  cout << "Wpisz 1, gdy chcesz usunąć pierwszy element "
	       << "kolejki"
	       << endl
	       << "Wpisz 2, gdy chcesz usunąć ostatni element "
	       << "kolejki"
	       << endl;  
	  cin >> liczba; 	
	  if (liczba == 1) {
	    List.UsunZprzodu();
	    cout << "Usunięto element pierwszy element kolejki"
		 << endl << endl;
	  }
	  else if ( liczba == 2 ) {
	    List.UsunZtylu();
	    cout << "Usunięto ostatni element kolejki"
		 << endl << endl;
	  }
	  else {
	    cout << "Błąd. Nieprawidłowy znak" << endl << endl;
	  }
	}
	break;
           
	//wyświetlanie zawartości  kolejki
      case 3:
	cout << endl << endl;
	if ( List.czyPusta() == true ) {
	  cout << "Błąd. Kolejka jest pusta"
	       << endl << endl;
	}
	else {
	  cout << "Zawartość kolejki" << endl
	       << "Ilość elementów kolejki: " << List.rozmiar()
	       << endl
	       << "Pierwszy element kolejki znajduje się na "
	       << "szczycie zestawienia" << endl;
	  List.Wyswietl();         //wyświetlenie zawartości kolejki
	}
	break;
	//usuwanie wszystkich elementów z kolejki
      case 4: 
	if ( List.czyPusta() == true ) {
	  cout << "Błąd. Kolejka jest pusta"
	       << endl << endl;
	}
	else {
	  while (!List.czyPusta() ) {
	    List.UsunZprzodu();
	    cout << "Usunięto element z kolejki"
		 << endl << endl;
	  }
	}
	if ( Kop.czyPusta() == true ) {
	  cout << "Błąd. Kolejka jest pusta"
	       << endl << endl;
	}
	else {
	  while (!Kop.czyPusta() ) {
	    Kop.UsunZprzodu();
	    cout << "Usunięto element z kolejki"
		 << endl << endl;
	  }
	}
	break;
	//sprawdza czy wpisane słowo jest palindromem
      case 5:
	cout << "Wpisz słowo: ";
	cin >> slowo;

	if ( jestPal(slowo, List, Kop ) == true ) {
	  cout << "Słowo " << slowo << " jest palindromem" 
	       << endl;
	}
	else {
	  cout << "Słowo " << slowo << " nie jest palindromem" 
	       << endl;
	}
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
