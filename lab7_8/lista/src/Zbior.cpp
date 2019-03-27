#include "Zbior.hh"



//Definicja metod operacji na zbiorach rozłącznych


//Konstruktor obiektu klasy Zbior
Zbior::Zbior (int rozmiar) 
{
  C = new WezelZbioru [rozmiar];        //tworzy liste zbiorów rozłącznych
}

//destruktor obiektu klasy Zbior
Zbior::~Zbior () 
{
  delete []C;
}

//tworzy osobne klastry dla wierzchołków
void Zbior::Make_set (const int &wierz) 
{
  C[wierz].rzad = 0;              //ustawia rząd drzewa
  C[wierz].rodzic = wierz;        
}


//zwraca reprezentanta zbioru zawierającego wierzcholek wierz
int Zbior::Find_set (const int &wierz)
{
  if ( C[wierz].rodzic == wierz ) 
    return (C[wierz]).rodzic;
  else
    return Find_set (C[wierz].rodzic);
}


//Łączy dwa osobne drzewa
void Zbior::Union ( const int &korzen_A, const int &korzen_B ) 
{
  if ( korzen_A != korzen_B ) {
    if ( C[korzen_A].rzad > C[korzen_B].rzad) {
      C[korzen_B].rodzic = korzen_A;
    }
    else {
      C[korzen_A].rodzic = korzen_B;
      if ( C[korzen_A].rzad == C[korzen_B].rzad )
	C[korzen_B].rzad++;
    }
  }
}

