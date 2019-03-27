#include "Lista.hh"
#include "Wezel.hh"

/*

 */

// zapisuje wartosci czasow trwania do pliku
bool ZapiszDoPliku (string nazwa, int *tab )
{
  ofstream PlikWyj;                  //deklaracja pliku do zapisu    
  PlikWyj.open( nazwa, fstream::out );       //otwórz strumień do zapisu
  for ( int i = 0 ; i < 100; ++i ) { 
    PlikWyj << tab[i] << endl;
  }
  if(PlikWyj.fail() )
    {
      PlikWyj.close(); //jeśli udało się zapisać, zamknij strumień
      cout << "Błąd. Nieudało się zapisać";
      return 1;
    }
  else {
    PlikWyj.close();
  }
  return 0;
}

// oblicza srednia
int ObliczSrednia ( string nazwa ) 
{
  int *t = new int[100];
  int elem =0 ;
  ifstream PlikWej;                  //deklaracja pliku do zapisu    
  PlikWej.open( nazwa, fstream::in );       //otwórz strumień do zapisu
  for (int i=0; !PlikWej.eof(); ++i ) { 
    PlikWej >> t[i];
  }
  PlikWej.close();
  for ( int j=0; j < 100; ++j) {
    elem += t[j];
  }
  elem = elem /100;
  return elem;
}
