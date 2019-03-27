#include "Krawedz.hh"

// definicja metod obiektu klasy Krawedz


// wpisuje wage dla krawedzi
void Krawedz::WpiszWageKraw (const int &wart) 
{
  waga = wart;
}


// wpisuje indeks pierwszego wierzcholka do obiektu typu krawedz
void Krawedz::WpiszIndPierwWierz (const int &wart) 
{
  wierzch_1 = wart;
}

// wpisuje indeks drugiego wierzcholka do obiektu typu krawedz
void Krawedz::WpiszIndDrugWierz (const int &wart)
{
  wierzch_2 = wart;
}


// pobiera wartosc elementu na krawedzi
int Krawedz::PobierzWage() 
{
  return waga;
}

// pobiera indeks pierszego wierzcholka
int Krawedz::PobierzIndPierwWierz()
{
  return wierzch_1;
}

// pobierz indeks drugiego wierzcholka
int Krawedz::PobierzIndDrugWierz()
{
  return wierzch_2;
}
