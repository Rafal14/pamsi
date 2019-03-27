#include "Palindrom.hh"


/*!\file 
 * \brief Plik zawiera definicje funkcji palindrom
 *
 */

/* Sprawdza czy wpisane słowo jest palindromem */
bool jestPal (string tekststr)
{
  int dlugosc=0;   //liczba znaków łańcucha 'tekststr'
  string napis;    //łańcuch znaków

  //zbadanie długości łańcucha znaków 
  for(string::iterator Iter=tekststr.begin();Iter!=tekststr.end();++Iter)
    {
      ++dlugosc;
    }
  int dlug = dlugosc -1;        //indeks ostatniego znaku z łańcucha

  //zwróć 'true', gdy łańcuch zawiera jeden znak 
  if( dlugosc == 1)
    {
      return true;
    }
  /*zwróć wartość 'false', gdy znaki z łańcucha: 
    pierwszy i ostatni nie są takie same  */              
  if( tekststr[0] != tekststr[dlug])
    {
      return false;            //wpisane słowo nie jest palindromem
    }
  for(int i=0; i<dlug; ++i)
    {
      jestPal( tekststr.substr(i+1,dlug-1) ); //wywołanie funkcji 
                                             //dla podciągu znaków
    }
  return true;                      //wpisane słowo jest palindromem
}
