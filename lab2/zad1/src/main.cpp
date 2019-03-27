/* Program realizuje funkcje sprawdzającą czy dane słowo
 * jest palindromem.
 *
 */

#include <iostream>
#include <string>
#include <vector>
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
  string slowo;                //łańcuch wpisanych znaków
  unsigned int dlugSlowa;   // dlugosc slowa
  vector<string> palList; 
 
  do {
    cout << "1.Sprawdzenie, czy wpisane słowo jest palindromem" 
	 << endl;
    cout << "2.Generowanie permutacji wpisnego słowa" << endl;
    cout << "3.Wyczyść tablice palindromów" << endl;
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
	//generuje permutacje słowa
      case 2:
       	cout << endl << "Wpisz słowo: ";
	cin >> slowo;
	dlugSlowa = slowo.size();
	genPermut (slowo, 0, dlugSlowa -1, palList);
	cout << endl << "Zawartość tablicy palList" << endl;
	wyswietl(palList);
	usunDup ( palList );    //usuwa duplikaty
	wyswietl(palList);       //po usunięciu duplikatów
	cout << endl << endl;
	break;
	//kiedy wpisano nieprawidłowy znak	
      case 3:
	if ( usun( palList ) == true ) {
	  cout << endl << "Usunięto zawartość tablicy palindromów"
	       << endl;
	}
	break;
      default:
	cout << endl << "Nieprawidłowy znak" << endl;
	break;
      }
  }while(opcja!=0);
  return 0;
}
