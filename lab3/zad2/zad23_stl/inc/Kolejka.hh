#ifndef KOLEJKA_HH
#define KOLEJKA_HH

/*!
 *
 * Plik zawiera definicje funkcji działających na kolejce
 */

#include <iostream>
#include <queue>

using namespace std;

// usuwa element z kolejki
bool UsunElem( queue<int> &Ko );

// dodaje element do kolejki
void DodajElem ( queue<int> &Ko, int wartosc  );

// usuwa wszystkie elementy kolejki
bool UsunWszystkie ( queue<int> &Ko );

// wyświetla zawartość kolejki
void WyswietlZawart (queue<int> &Ko);

//dodaje wartości losowe z pliku do kolejki
void DodajLos(const string &NazwaPliku, queue<int> &Ko);

#endif
