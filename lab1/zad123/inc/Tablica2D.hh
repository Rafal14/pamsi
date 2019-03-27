#ifndef TABLICA2D_HH
#define TABLICA2D_HH

#include <iostream>

/*
 * Prototypy funkcji
 *
 */

using namespace std;

/* 
 * Wpisuje wygenerowane wartości pseudolosowe do zaalokowanej 
 * dwuwymiarowej tablicy dynamicznej
 *
 */
int** Wpisz (const int &wier, const int &kol);


/*
 * Wypisuje zawartosc zaalokowanej dwuwymiarowej tablicy dynamicznej
 *
 */
int Wyswietl(int** wskaz,const int &wier, const int &kol); 

/*
 * Znajduje wartość maksymalna w dwuwymiarowej tablicy dynamicznej
 *
 */
int Znajdz_max(int** wskaz, const int &wier, const int &kol);



#endif
