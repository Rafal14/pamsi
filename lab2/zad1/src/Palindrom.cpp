#include "Palindrom.hh"


/*!\file 
 * \brief Plik zawiera definicje funkcji palindrom
 *
 */



// Sprawdza czy słowo jest palindromem
bool jestPal (string tekststr) {
  int dlugosc = tekststr.length();           //długość słowa
  string pierwsza = tekststr.substr(0,1);    //pierwsza litera w wyrazie
  string ostatnia = tekststr.substr(dlugosc-1, 1  ); // ostatnia litera słowa
  if ( (pierwsza == ostatnia) && ( dlugosc > 1 ) ) { // pierwsza lit == druga
    return jestPal (tekststr.substr(1, dlugosc - 2) );  //returencja
  }
  if ( dlugosc < 2  ) { return true; }          //gdy ciąg jednoznakowy
  return false;                             //nie jest palindromem
}




//wyswietla palindromy
void wyswietl(vector<string> Pal)
{
  if ( !Pal.empty() )  {                //gdy niepusta tablica
    cout << endl << "Tablica palindromów" << endl;
    for ( unsigned int j = 0; j < Pal.size() ;++j)
      {
	cout << Pal[j];
	cout << endl;
      }
    cout << endl;
  }
  else {
    cout << "Tablica jest pusta" << endl;
  }
  cout << endl << "Liczba palindromów: " << Pal.size() << endl;
}

/* usuwa duplikaty */
void usunDup(vector<string> &Pal)
{
  if ( (Pal.size() != 1) && (!Pal.empty()) ) {
    cout << endl << "Po usunięciu duplikatów" << endl;
    for (unsigned int i = 0; i < Pal.size() ;++i) {
      for (unsigned int j = 0; j < Pal.size() ;++j) {
	if ( Pal[i] == Pal[j] )   {
	  Pal.erase(Pal.begin() +j  );
	}
      }
    }
  }
}

// generuje permutcje palindromów
void genPermut ( string &nazwa, unsigned int licz, unsigned int maxInd, vector<string>& Pal )
{
  unsigned int j;
  if ( licz == maxInd ) {
    if ( jestPal(nazwa) == true ) {
      Pal.push_back(nazwa);
    }
  }    
  else {
    for (j=licz; j <= maxInd; j++) {
      swap( nazwa[licz], nazwa[j] ); //zmien elem na pozycjach
      genPermut(nazwa, licz + 1, maxInd, Pal);
      swap( nazwa[licz], nazwa[j] );   //powrót do orginału
    }
  }
}



//czyści tablicę palindrów
bool usun( vector<string> &Pal ) {
  if ( Pal.empty() ) {
    cout << endl << "Tablica jest pusta" << endl;
    return false;
  }
  while(!Pal.empty() ) {
    Pal.pop_back();
  }
  return true;
}
