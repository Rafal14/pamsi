//plik główny programu działający na kolejce FIFO

#include "Node.hh"
#include "Queue.hh"

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
  int option;                 //wartość odcztanej opcji
  int number;                 // liczba
  Queue Line;                 //zainicjowanie obiektu klasy kolejka FIFO
  do {
    cout << "1.Dodawanie elementu do kolejki"
	 << endl;
    cout << "2.Usuwanie elementu z kolejki" << endl;
    cout << "3.Wyświetlanie zawartości" << endl;
    cout << "4.Usuwanie wszystkich elementów z kolejki"
	 << endl;
    cout << "0.Koniec"
	 << endl;
    cout << "Wybierz opcję" << "\t";
    cin >> option;
    cout << endl;

    switch(option)
      {
	// zakończenie działanie programu
      case 0: break;
	// dodawnie pierwszego elementu do tablicy
      case 1:       
	cout << "Wpisz element: ";    	
	cin >> number;
	//dodaj liczbe z przodu listy
	Line.enqueue ( number );
	cout << "Dodano element do kolejki"
	     << endl;
	cout << endl;
	break;
	//usuwanie pojedyczego elementu
      case 2:

	if( Line.empty() == true ) {
	  cout << endl << "Błąd. Kolejka jest pusta"
	       << endl << endl;
	}
	else {
	  Line.dequeue();
	  cout << "Usunięto element z kolejki"
		 << endl << endl;
	}
	break;

	//wyświetlanie zawartości kolejki
      case 3:
	cout << endl << endl;
	if ( Line.empty() == true ) {
	  cout << "Błąd. Kolejka jest pusta"
	       << endl << endl;
	}
	else {
	  cout << "Zawartość kolejki" << endl
	       << "Pierwszy element kolejki znajduje się "
	       << "na szczycie zestawienia" << endl;
	  Line.Display();         //wyświetlenie zawartości kolejki
	}
	break;
	//usuwanie wszystkich elementów z kolejki
      case 4: 
	if ( Line.empty() == true ) {
	  cout << "Błąd. Kolejka jest pusta"
	       << endl << endl;
	}
	else {
	  while (!Line.empty() ) {
	    Line.dequeue();
	    cout << "Usunięto element na początku kolejki"
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
  }while(option!=0);
  return 0;
}
