#ifndef PALINDROM_HH
#define PALINDROM_HH

/*!
 * \file
 * \brief Prototyp funkcji sprawdzania palindromu i generowania 
 *  permutacji
 *
 * Plik zawiera protoryp funkcji sprawdzania 
 * czy wprowadzone ze standardowego wejścia słowo
 * jest palindromem
 */

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


/*!
 * \brief Sprawdza czy wpisane słowo jest palindromem
 *
 * Funkcja jest wywoływna rekurencyjnie
 *
 * \param[in] tekststr - łańcuch znaków wpisanego słowa
 *
 * \retval true  - jeżeli wpisane słowo jest palindromem
 * \retval false - jeśli wpisane słowo nie jest palindromem
 *
 */
bool jestPal (string tekststr);


/*!
 * \brief Generuje możliwe permutacje dla zadanego słowa
 *
 * Funkcja jest wywoływna rekurencyjnie
 *
 * 
 *
 *
 *   
 *
 */
void genPermut ( string &nazwa, unsigned int licz, unsigned int maxInd, vector<string>& Pal);


// wyswietla zestawienie palindromów
void wyswietl(vector<string> Pal);

//usuwa duplikaty
void usunDup(vector<string> &Pal);

//czyści tablicę palindrów
bool usun( vector<string> &Pal );

#endif
