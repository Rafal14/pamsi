/* Program generuje liczby losowy z zadanego zakresu 
 * i zapisuje te liczby w pliku
 */

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {
  int przedzial;                    //zakres generowanych liczb
  int liczba_losowa;
  string NazwaPliku;                //nazwa pliku do zapisu
  ofstream PlikWyj;                  //deklaracja pliku do zapisu             
  cout << "Podaj zakres generowanych liczb: ";
  cin >> przedzial;
  cout << "Podaj nazwę pliku do zapisu: ";
  cin >> NazwaPliku;
  PlikWyj.open( NazwaPliku, fstream::out );       //otwórz strumień do zapisu
  for ( int i = 0 ; i < przedzial; ++i ) { 
    liczba_losowa = rand() % przedzial;          //wyznaczenie liczby losowej
    PlikWyj << liczba_losowa << endl;
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
