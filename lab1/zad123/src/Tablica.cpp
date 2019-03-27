#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Tablica.hh"

/*
 * Plik zawiera definicje funkcji odczytu i zapisu tablicy jednowymiarowej
 * 
 */


/* Funkcja wczytuje tablice jednowymiarowa z pliku teksowego */
int* Wczytaj_z_pliku_tekst( const string &NazwaPlik, int &rozmiar)
{
  ifstream PlikWej;   //utwórz strumień wejściowy dla pliku
  int wartosc;        //wartość odczytywana
  int *wsktab;        //wskaźnik na tablice jednowymiarowa
  rozmiar = 0;        //ilość elementów w tablicy
  PlikWej.open( NazwaPlik, fstream::in );
  
  for(; !PlikWej.eof(); ++rozmiar)
    {
      PlikWej >> wartosc;
    }
  PlikWej.close();    //zamknięcie strumienia odczytu z pliku
  //--rozmiar;        
  
  // czy plik nie jest pusty
  if(rozmiar!=0)
    {
      wsktab = new int[rozmiar];   // alokuje tablice jednowym
      PlikWej.open( NazwaPlik, fstream::in );

      for(int licz=0; licz<rozmiar; ++licz)
	{
	  PlikWej >> wartosc;    //pobierz wartość z pliku
	  wsktab[licz] = wartosc;//wpisz wartość odczytana do tablicy
	}
      PlikWej.close();           // zamknięcie strumienia plikowego
    }
  else
    {
      cerr << endl
	   << "Błąd odczytu pliku"
	   << endl;
    }
  cout << "Wczytano tablicę jednowymiarową:" << endl;
  for(int i=0; i<rozmiar; ++i) { cout<< wsktab[i] << endl; }
  cout << endl;
  return wsktab;
}


/* Funkcja zapisuje wcześniej wczytaną tablicę w pliku wyjściowym */
int Zapisz_tekst(int* wskTab, int rozmiar, const string &NazwaPlik)
{
  ofstream PlikWyj;   //deklaracja strumienia wyjściowego dla zapisu

  PlikWyj.open( NazwaPlik, fstream::out );
  for(int licz=0; licz<rozmiar; ++licz)
    {
      PlikWyj << wskTab[licz]
	      << endl;
    }
  if(!PlikWyj.fail() )
    {
      PlikWyj.close(); //jeśli udało się zapisać, zamknij strumień
      return 0;
    }
  else
    PlikWyj.close();
    return 1;
}

/* Funkcja wczytuje tablicę jednowymiarową z pliku binarnego */
int* Wczytaj_z_pliku_bin( const string &NazwaPlik, int &rozmiar)
{
  char *tchar = new char[sizeof(int)];
  ifstream PlikWej(NazwaPlik, ios::binary);
  PlikWej.read(tchar, sizeof(int));
 
  int* wsktab = (int*)(tchar);  //rzutowanie zawartości tablicy z char na int
  for(int i=0; i<rozmiar; ++i) { cout<< wsktab[i] << endl; }
  return wsktab;
}

/* Funkcja pozwala na zapisanie tablicy jednowymiarowej do pliku*/
int Zapisz_bin(int* wskTab, int rozmiar, const string &NazwaPlik)
{
  ofstream PlikWyj( NazwaPlik, ios::binary );
  char* tablic = (char*)(wskTab);
  PlikWyj.write( tablic, sizeof(char) );

  return 0;
}
