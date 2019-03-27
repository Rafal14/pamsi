/* Program realizuje funkcje wypełnienia wartościami losowymi, 
 * wyświetlania i znajdowania wartości maksymalnej tablicy 
 * dwuwymiarowej alokowanej dynamicznie. Ponadto umożliwia 
 * wczytanie i zapisanie tablicy jednowymiarowej 
 * z pliku teksowego i binarnego oraz wylicznie silni i potęgi.
 */

#include <iostream>
#include "Tablica2D.hh"
#include "Tablica.hh"
#include "Potega_silnia.hh"

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
  int wiersze;                  // liczba wierszy tablicy
  int kolumny;                  // liczba kolumn tablicy
  int** wtab;                   // wskaźnik wskazujacy na tab wsk
  int* wskaz;                   // wskaźnik na tab jednowymiarowa
  int czy_istnieje_tablica = 1; //tablica nie została zadeklarowana
  int czy_tablica_wczytana = 1; //tablica 1-wym nie została wczytana
  string nazwa_plik;            //nazwa pliku
  int roz;                      // rozmiar tablicy jednowymiarowej
  do {
    cout << "1.Wypełnianie tablicy" << endl;
    cout << "2.Wyświetlanie tablicy" << endl;
    cout << "3.Znajdowanie wartości maksymalnej" << endl;
    cout << "4.Zapisanie tablicy jednowymiarowej do pliku tekstowego"
	 << endl;
    cout << "5.Wczytanie tablicy jednowymiarowej z pliku tekstowego"
	 << endl;
    cout << "6.Zapisanie tablicy jednowymiarowej do pliku binarnego"
	 << endl;
    cout << "7.Wczytanie tablicy jednowymiarowej z pliku binarnego"
	 << endl;
    cout << "8.Potęgowanie liczby x do potęgi p"
	 << endl;
    cout << "9.Silnia z liczby x"
	 << endl;
    cout << "0.Koniec" << endl;
    cout << "Wybierz opcję" << "\t";
    cin >> opcja;

    switch(opcja)
      {
	// zakończenie działanie programu
      case 0: break;
	// wypełnienie tablicy alokowanej dynamicznie wartościami 
	// wpisanymi na standardowe wejście 
      case 1: 
	{
	  cout << endl << "Podaj wielkość tablicy" << endl;
	  cout << "Ilość wierszy: ";
	  cin >> wiersze;
	  cout << "Ilość kolumn: ";
	  cin >> kolumny;
	  cout << endl 
	       << "Podaj zakres generowanych liczb: od 0 do ";

	  // alokuje w sposob dynamiczny  zadeklarowna tablice   
	  int** tab = Wpisz(wiersze, kolumny);
	  wtab = tab;
	  czy_istnieje_tablica = 0;    // znacznik istnienia tablicy
	}	  
	break;
	
	// wyświetla zawartość dwuwymiarowej tablicy
      case 2:
	{
	  if(czy_istnieje_tablica == 0)
	    {
	      Wyswietl(wtab, wiersze, kolumny);
	    }
	  else
	    cerr << "Błąd tablica nie zostala zadeklarowana";
	}	
	break;
	// znajduje i wyświetla maksymalna wartość w tablicy
      case 3:
	{
	  if(czy_istnieje_tablica == 0)
	    {
	      Znajdz_max(wtab, wiersze, kolumny);
	      cout << "Wartość maksymalna to: "
		   << Znajdz_max(wtab, wiersze, kolumny)
		   << endl << endl;
	    }
	  else
	    cerr << "Błąd tablica nie zostala zadeklarowana"
		 << endl
		 << endl;
	}	
	break;
	// zapisuje wczytana tablice do pliku tekstowego
      case 4:
	{
	  if(czy_tablica_wczytana == 0)
	    {
	      cout << "Podaj nazwe pliku do zapisu: ";
	      cin >> nazwa_plik;
	      cout << endl;
	      if( Zapisz_tekst(wskaz, roz, nazwa_plik) ==0 )
		{
		  cout << "Plik został poprawnie zapisany"
		       << endl << endl;
		} 
	    }
	  else 
	    cerr << "Nie wczytano tablicy jednowymiarowej"
		 << endl
		 << endl;
	}
	break;
	// wczytuje talice z pliku tekstowego

      case 5:
	cout << endl << endl
	     << "Podaj nazwę pliku: ";
	cin >> nazwa_plik;
	wskaz = Wczytaj_z_pliku_tekst(nazwa_plik,roz);
	czy_tablica_wczytana = 0;
	break;

	// zapisuje tablice do pliku binarnego
      case 6:
	{
	  if(czy_tablica_wczytana == 0)
	    {
	      cout << "Podaj nazwe pliku do zapisu: ";
	      cin >> nazwa_plik;
	      cout << endl;
	      if( Zapisz_bin(wskaz, roz, nazwa_plik) ==0 )
		{
		  cout << "Plik został poprawnie zapisany"
		       << endl << endl;
		} 
	    }
	  else 
	    cerr << "Nie wczytano tablicy jednowymiarowej"
		 << endl
		 << endl;
	}
	break;

	// wczytuje tablice z pliku binarnego
      case 7:
	// Wpisano nieprawidłowy znak
	cout << endl << endl
	     << "Podaj nazwę pliku: ";
	cin >> nazwa_plik;
	wskaz = Wczytaj_z_pliku_bin(nazwa_plik,roz);
	czy_tablica_wczytana = 0;
	break;
	//potęguje zadaną liczbę do określonej potęgi
      case 8:
	int podstawa;     //podstawa potęgi
	int wykladnik;    //wykładnik potęgi
	cout << endl << "Potegowanie" << endl
	     << "Podaj wartość x: ";
	cin >> podstawa;
	cout << "Podaj wartość p: ";
	cin >> wykladnik;
	cout << endl << "\t " << wykladnik << endl;
	cout << "\t" << podstawa;
	cout << " = " << Potega(podstawa,wykladnik)
	     << endl << endl;
	break;
	//oblicza silnię dla zadanej wartości x
      case 9:
	int argument;
	cout << "Silnia" << endl
	     << "Podaj wartość x: ";
	cin >> argument;
	cout << "\t" << argument << "!"
	     << " = " << Silnia(argument);
	cout << endl << endl;
	break;
      default:
	cerr << endl << "Nieprawidłowy znak" << endl;
	break;
      }
  }while(opcja !=0);    // powtarzaj pętle dopóki  
                        // nie pojawi sie 0

  // usuń dwuwymiarowa tablice, jeżeli zostala utworzona
  if(czy_istnieje_tablica == 0)
    {
      for(int i=0; i<wiersze; ++i)
	{
	  delete [] wtab[i];
	}
      delete [] wtab;
    }

  // usuń jednowymiarowa tablice, jeżeli zostala zaalokowana
  if(czy_tablica_wczytana == 0)
    {
      delete [] wskaz;
    }
  return 0;
}
