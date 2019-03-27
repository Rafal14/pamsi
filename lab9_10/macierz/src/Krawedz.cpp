#include "Krawedz.hh"

// definicja metod obiektu klasy Krawedz


// wpisuje wagę dla krawedzi
void Krawedz::WpiszWageKraw (const int &wart) 
{
  waga = wart;
}


// wpisuje indeks pierwszego wierzchołka do obiektu typu krawędz
void Krawedz::WpiszIndPierwWierz (const int &wart) 
{
  wierzch_1 = wart;
}

// wpisuje indeks drugiego wierzchołka do obiektu typu krawędz
void Krawedz::WpiszIndDrugWierz (const int &wart)
{
  wierzch_2 = wart;
}


// pobiera wagę krawedzi
int Krawedz::PobierzWage() 
{
  return waga;
}

// pobiera indeks pierwszego wierzchołka
int Krawedz::PobierzIndPierwWierz()
{
  return wierzch_1;
}

// pobierz indeks drugiego wierzchołka
int Krawedz::PobierzIndDrugWierz()
{
  return wierzch_2;
}
