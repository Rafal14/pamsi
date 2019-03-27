/* Program realizuje funkcje sprawdzającą czy dane słowo
 * jest palindromem.
 *
 */

#include <iostream>
#include <string>
#include "Palindrom.hh"

using namespace std;


/*!
 *\file
 *\brief Plik główny programu.
 *
 * Plik zawiera funkcje main programu.
 *
 */


int main()
{
  int opcja=0;
  string slowo;           //łańcuch wpisanych znaków
  
  do {
    cout << "1.Sprawdzenie, czy wpisane słowo jest palindromem" 
	 << endl;
    cout << "0.Koniec" << endl;
    cout << "Wybierz opcję" << "\t";
    cin >> opcja;
    cout << endl;
    switch(opcja)
      {
	//zakończenie działania programu
      case 0: break;
	//sprawdzenie czy wpisane słowo jest palidromem
      case 1:
	{
	  cout << "Wpisz słowo: ";
	  cin >> slowo;          //wpisz znaki do łańcucha ze stdin
	  cout << endl;
	  //gdy słowo jest palidromem
	  if ( (jestPal (slowo)) == true )
	    {
	      cout << "Słowo " 
		   << slowo
		   << " jest palindromem"
		   << endl;
	    }
	  //jeżeli nie jest palidromem
	  else
	    {
	      cout << "Słowo " 
		   << slowo
		   << " nie jest palindromem"
		   << endl;
	    }
	  break;
	}
      default:
	cout << endl << "Nieprawidłowy znak" << endl;
	break;
      }
  }while(opcja!=0);

  return 0;
}
