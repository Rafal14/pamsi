//plik główny programu działający na kolejce FIFO

#include "Node.hh"
#include "Queue.hh"

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
  int option;                 //wartość odcztanej opcji
  int number;                 // liczba
  string namFile;            //nazwa pliku z wartościami losowymi
  Queue Line;                 //zainicjowanie obiektu klasy kolejka FIFO
  timeval t1, t2;
  double time_ms;            //uzyskany czas
  do {
    cout << "1.Dodawanie elementu do kolejki"
	 << endl;
    cout << "2.Usuwanie elementu z kolejki" << endl;
    cout << "3.Wyświetlanie zawartości" << endl;
    cout << "4.Usuwanie wszystkich elementów z kolejki"
	 << endl;
    cout << "5.Dodawanie elementów losowych do kolejki"
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
	//dodawanie elementów losowych na stos
      case 5:
	cout << "Podaj nazwa pliku do odczytu: ";
	cin >> namFile;
	// start timera
	gettimeofday(&t1, NULL);         //załączenie timera
	InsertRandValues( namFile, Line );      //wykownywanie funkcji
	gettimeofday(&t2, NULL);         //wyłączenie timera
	
	cout << endl << endl <<  "Czas zmierzony" << endl;
	//oblicza i wyświetla obliczony czas w ms
        time_ms = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
	time_ms += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
	cout << time_ms << " ms.\n";  
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
