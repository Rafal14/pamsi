#ifndef KRAWEDZ_HH
#define KRAWEDZ_HH

// definicja obiektu typu krawedz


class Krawedz {

private:
  int waga;         // waga krawedzi
  int wierzch_1;    // pierwszy z wierzcholków przylegajacych do krawedzi
  int wierzch_2;    // drugi z wierzchołków przylegający do krawedzi

public:

  // wpisuje wage dla krawedzi
  void WpiszWageKraw (const int &wart);
  // wpisuje indeks pierwszego wierzcholka do obiektu typu krawedz
  void WpiszIndPierwWierz (const int &wart);
  // wpisuje indeks drugiego wierzcholka do obiektu typu krawedz
  void WpiszIndDrugWierz (const int &wart);

  // pobiera wartosc elementu na krawedzi
  int PobierzWage();
  // pobiera indeks pierszego wierzcholka
  int PobierzIndPierwWierz();
  // pobierz indeks drugiego wierzcholka
  int PobierzIndDrugWierz();
};


#endif
