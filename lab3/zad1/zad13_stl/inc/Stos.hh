#ifndef STOS_HH
#define STOS_HH

/*!
 *
 * Plik zawiera definicje funkcji działających na stosie
 */

#include <iostream>
#include <stack>

using namespace std;

// usuwa element o zadanej pozycji ze stosu
bool UsunElem( stack<int> &St, unsigned int elem );

// dodaje element do stosu
bool DodajElem ( stack<int> &St, unsigned int elem, int wartosc  );

// usuwa wszystkie elementy stosu
bool UsunWszystkie ( stack<int> &St );

// wyświetla zawartość stosu
void WyswietlZawart (stack<int> &St);

//dodaje wartości losowe do stosu
void DodajLos(const string &NazwaPliku, stack<int> &St); 

#endif
