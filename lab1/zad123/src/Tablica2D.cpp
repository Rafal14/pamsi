#include <iostream>
#include <cstdlib>
#include "Tablica2D.hh"

/*
 * Plik zawiera definicje funkcji wpisywania losowych wartości 
 * do zadeklarowanej tablicy, jej wyświetlania i znajdowania wartości 
 * maksymalnej 
 */

// wpisz wartości pseudolosowe do zadeklarowanej tablicy
int** Wpisz (const int &wier, const int &kol)
{
  int zakres;
  int liczba_losowa;
  cin >> zakres;                        // wczytaj maksymalny zakres
                                        // generowanych liczb
  int ** tablica= new int * [wier];     // zaalokuj tablice 
                                        // dynamiczna w pamieci
  for(int i = 0; i<wier; ++i)
    {
      tablica[i] = new int [kol];
      for(int j = 0; j<kol; ++j)
	{
	  //generuje liczby losowe od 0 do wartosc
	  liczba_losowa = rand() % zakres;  
	  // wpisuje liczby losowe do tablicy
	  tablica[i][j] = liczba_losowa;  
	}
    }
  return tablica;  //zwraca wskaznik na wskaznik tablicy dynamicznej
}

//wyświetla tablicę dwuwymiarową
int Wyswietl(int** wskaz, const int &wier, const int &kol)
{

      for(int i = 0; i<wier; ++i)
	{
	  for(int j = 0; j<kol; ++j)
	    {
	      cout << wskaz[i][j]  << "\t";
	    }
	  cout << endl;
	}
      cout << endl << endl;
      return 0;
}

// znajduje wartość maksymalną w tablicy
int Znajdz_max(int** wskaz, const int &wier, const int &kol)
{
  int wartosc_max;
  wartosc_max = wskaz[0][0];
  for(int i = 0; i<wier; ++i)
    {
      for(int j = 0; j<kol; ++j)
	{
	  if(wartosc_max < wskaz[i][j])
	    {
	      wartosc_max = wskaz[i][j];
	    }
	}
    }
  return wartosc_max;  // zwróć wartość maksymalną
 }








/*
istream& operator >> (istream &StrmWej, char &Liczba)
{
  StrmWej >> Liczba;

  if (cin.fail() ) {
    cerr << endl << "Blad. Wprowadzono bledne znaki." << endl;
    cin.clear();
    cin.ignore();
  }

  return StrmWej;
}

ostream& operator << (ostream &StrmWyj, const char &Liczba)
{
  StrmWyj << Liczba
	  << "\t"
	  << endl;

  return StrmWyj;
}
*/

/*********************************************************/
