#include "Potega_silnia.hh"

/*
 * Plik zawiera definicje funkcji silnia i potega
 * wywoływanych rekurencyjnie
 *
 */


int Potega(int x, int p)
{
  if(p == 0) { return 1; }   // zwróć 1 gdy podstawa to 0
  if(p == 1) { return x; }   // zwróć x gdy wykładnik to x
  return x * Potega(x, p-1);  //rekurencyjne wywolanie funkcji
}



int Silnia(int x)
{
  if( x == 0 || x == 1)    //warunek to silni z 0 i 1
    {
      return 1;
    }
  else
    return x * Silnia(x-1); //rekurencyjne wywołanie funkcji silnia
}

