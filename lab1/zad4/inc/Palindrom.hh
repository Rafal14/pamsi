#ifndef PALINDROM_HH
#define PALINDROM_HH

/*!
 * \file
 * \brief Prototyp funkcji sprawdzania palindromu
 *
 * Plik zawiera protoryp funkcji sprawdzania 
 * czy wprowadzone ze standardowego wejścia słowo
 * jest palindromem
 */

#include <string>
#include <iostream>

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


#endif
