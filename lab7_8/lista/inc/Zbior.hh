#ifndef ZBIOR_HH
#define ZBIOR_HH


//Struktura wezła listy zbiorów rozłącznych
struct WezelZbioru
{
  int rodzic;
  int rzad;
};

//Definicja klasy Zbior
class Zbior
{
private:
  //wskaznik na tablice zbiorów rozłącznych
  WezelZbioru* C;
public:
  //konstruktor
  Zbior (int rozmiar);
  //destruktor
  ~Zbior();

  //operacje działań na zbiorach rozłącznych
  
  //zwraca reprezentanta zbioru zawierającego wierzcholek wierz
  int Find_set (const int &wierz);

  //tworzy osobne klastry dla wierzchołków
  void Make_set (const int &wierz);

  //Łączy dwa osobne drzewa
  void Union ( const int &korzen_A, const int &korzen_B );
};


#endif
