//plik główny programu implementcji listy jednokierunkowej

#include "Wezel.hh"
#include "Lista.hh"

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
  int liczba; 
  Lista List;
  do {
    cout << "1.Dodawanie pierwszego elementu do listy"
	 << " jednokierunkowej" << endl;
    cout << "2.Usuwanie pojedynczego elementu" << endl;
    cout << "3.Wyświetlanie zawartości" << endl;
    cout << "4.Usuwanie wszystkich elementów"
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
	// dodawnie pierwszego elementu do tablicy
      case 1:
	cout << "Wpisz 1, gdy chcesz dodać element z przodu listy"
	     << endl
	     << "Wpisz 2, gdy chcesz dodać element na koniec listy"
	     << endl;  
	cin >> liczba; 	
	cout << "Wpisz element: "; 
	if (liczba == 1) {
	  cin >> liczba; 
	  List.DodajNapocz(liczba);   //dodaj liczbe z przodu listy
	  cout << "Dodano element na początek listy"
	       << endl;
	}
	else if ( liczba == 2 ) {
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
	  List.UsunZprzodu();
	  cout << "Usunięto element z początku listy"
	       << endl << endl;
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
	    cout << "Usunięto element z przodu listy"
		 << endl << endl;
	  }
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
