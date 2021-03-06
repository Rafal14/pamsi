/* Program generuje liczby losowe do grafu z zadanego zakresu 
 * i zapisuje te liczby w pliku
 */

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
  int wierzcholki;                    //zakres generowanych liczb
  int liczba_losowa;
  float liczba, gestosc;

  string nazwa;
  //nazwa pliku do zapisu
  string NazwaPliku[100]= {
    "1.dat",
    "2.dat",
    "3.dat",
    "4.dat",
    "5.dat",
    "6.dat",
    "7.dat",
    "8.dat",
    "9.dat",
    "10.dat",
    "11.dat",
    "12.dat",
    "13.dat",
    "14.dat",
    "15.dat",
    "16.dat",
    "17.dat",
    "18.dat",
    "19.dat",
    "20.dat",
    "21.dat",
    "22.dat",
    "23.dat",
    "24.dat",
    "25.dat",
    "26.dat",
    "27.dat",
    "28.dat",
    "29.dat",
    "30.dat",
    "31.dat",
    "32.dat",
    "33.dat",
    "34.dat",
    "35.dat",
    "36.dat",
    "37.dat",
    "38.dat",
    "39.dat",
    "40.dat",
    "41.dat",
    "42.dat",
    "43.dat",
    "44.dat",
    "45.dat",
    "46.dat",
    "47.dat",
    "48.dat",
    "49.dat",
    "50.dat",
    "51.dat",
    "52.dat",
    "53.dat",
    "54.dat",
    "55.dat",
    "56.dat",
    "57.dat",
    "58.dat",
    "59.dat",
    "60.dat",
    "61.dat",
    "62.dat",
    "63.dat",
    "64.dat",
    "65.dat",
    "66.dat",
    "67.dat",
    "68.dat",
    "69.dat",
    "70.dat",
    "71.dat",
    "72.dat",
    "73.dat",
    "74.dat",
    "75.dat",
    "76.dat",
    "77.dat",
    "78.dat",
    "79.dat",
    "80.dat",
    "81.dat",
    "82.dat",
    "83.dat",
    "84.dat",
    "85.dat",
    "86.dat",
    "87.dat",
    "88.dat",
    "89.dat",
    "90.dat",
    "91.dat",
    "92.dat",
    "93.dat",
    "94.dat",
    "95.dat",
    "96.dat",
    "97.dat",
    "98.dat",
    "99.dat",
    "100.dat"
  };
 
  ofstream PlikWyj;                  //deklaracja pliku do zapisu             
  cout << "Podaj liczbe wierzcholkow: ";
  cin >> wierzcholki;
  cout << "Podaj gestosc grafu: ";
  cin >> gestosc;
  
  liczba = wierzcholki * (wierzcholki-1);
  liczba = liczba * gestosc;
  liczba *= 0.5;
  int krawedzie = floor( liczba );

  for ( int j=0; j < 100; ++j ) {
    nazwa = NazwaPliku[j];

    PlikWyj.open( nazwa, fstream::out );       //otwórz strumień do zapisu

    PlikWyj << wierzcholki;
    PlikWyj << endl;

    PlikWyj << krawedzie;
    PlikWyj << endl;
    PlikWyj << endl;

    for ( int i = 0 ; i < krawedzie; ++i ) { 
      do {
	liczba_losowa = rand() % krawedzie;      //wyznaczenie liczby losowej
      }while(liczba_losowa == 0);
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
  }
}
