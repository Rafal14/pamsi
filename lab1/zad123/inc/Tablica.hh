#ifndef TABLICA_HH
#define TABLICA_HH

#include <iostream>

/*
 * Prototypy funkcji
 *
 */

using namespace std;




/* 
 * Wczytuje tablice jednowymiarowa z pliku tekstowego
 *
 */
int* Wczytaj_z_pliku_tekst( const string &NazwaPlik, int &wielkosc);


/* 
 * Wczytuje tablice jednowymiarowa z pliku binarnego
 *
 */
//int** Wczytaj_z_pliku_bin( const string &NazwaPlik );


/*
 * Zapisuje tablice jednowymiarowa do pliku tekstowego
 *
 */
int Zapisz_tekst(int* wskaz, int rozmiar, const string &NazwaPlik); 




int* Wczytaj_z_pliku_bin( const string &NazwaPlik, int &rozmiar);

int Zapisz_bin(int* wskTab, int rozmiar, const string &NazwaPlik);

#endif
