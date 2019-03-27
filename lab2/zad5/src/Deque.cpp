#include "Deque.hh"
#include "Wezel.hh"



/* Metoda klasy Deque
 *
 * Sprawdza czy zainicjowany obiekt typu Deque jest pusty
 *
 * \retval true  - jeżeli jest pusta
 * \retval false - w przeciwnym wypadku 
 */
bool Deque::czyPusta() const
{
  if (glowa == NULL ) 
    return true;
  else
    return false;
}



//dodaje element na początek kolejki
void Deque::DodajNapocz (const char &el)
{
  Wezel* obiekt = new Wezel;    //alokacja nowego wezła listy
  
  if ( glowa == NULL ) {
    ogon = obiekt;
  }

  obiekt->element = el;        //wpisz nowy element do węzła listy  
  obiekt->nastepny = glowa;   //wskazanie na następny element       
  glowa = obiekt;            //niech glowa pokazuje na nowy obiekt
  cout << endl;
  ++dlugosc;
}

//dodaje element na koniec kolejki
void Deque::DodajZtylu (const char &el)
{
  Wezel* obiekt = new Wezel;    //alokacja nowego wezła listy
  obiekt->element = el;
  if ( glowa == NULL ) {       
    glowa = obiekt;            //warunek dla pierwszego elementu
    ogon = obiekt;   //głowa i ogon wskazują na pierwszy elem
  }
  else {
    ogon->nastepny = obiekt;  //dowiązanie do następnego elementu
    ogon = obiekt;         //ogon wskazuje na ostatnio dodany elem
  }
  ++dlugosc;
}

//usuwa pierwszy element z kolejki
char Deque::UsunZprzodu()
{
  //pierwszy element z listy
  Wezel* usuwanyWezel = glowa;
  //głowa listy wskazuje na następny element z listy
  glowa = usuwanyWezel->nastepny;
  char elem = usuwanyWezel->element;           // ----------
  delete usuwanyWezel; //usuniecie pierwszego elementu z listy
  --dlugosc;
  return elem;                 //-----------
}   


//usuwa element ostatniego elementu kolejki
char Deque::UsunZtylu()
{
  Wezel* wskaz = glowa->nastepny;
  while ( (wskaz->nastepny) != ogon ) {
    wskaz = wskaz->nastepny;
  }
  Wezel* usuwany = ogon;
  char elem = usuwany->element;    //          -------------
  delete usuwany;
  ogon = wskaz;
  wskaz->nastepny = NULL;
  --dlugosc;
  return elem;             //     ------
}

//wyświetla zawartość kolejki deque
void Deque::Wyswietl() 
{
  Wezel* wskaz = glowa;
  while ( (wskaz->nastepny)!=NULL ) {
    cout << wskaz->element;
    cout << endl;
    wskaz = wskaz->nastepny;        
  }
  cout << wskaz->element;           //wyswietla ostatni elem listy
  cout << endl << endl;
}

//zwraca liczbę elementów znajdujących się w kolejce
int Deque::rozmiar() const {
  return dlugosc;
}



Wezel* Deque::pierwszy() {     //zwraca wskaz na elem pierwszy
  return glowa;
}

Wezel* Deque::ostatni() {      //zwraca wskaz na elem ostatni
  return ogon;
}



//sprawdza czy słowo jest palindromem
bool jestPal(const string &napis, Deque &Pal,Deque &Kopia) { 
  for ( unsigned int i=0; i< napis.length() ; ++i) {
    Pal.DodajNapocz( napis[i] );
  }
  Pal.Wyswietl();
  for ( unsigned int j=0; j< napis.length() ; ++j) {
    Kopia.DodajZtylu( napis[j] );
  }
  Kopia.Wyswietl();
  if ( Pal.rozmiar() == 1 )
    return true;
  char znak;
  char znakkop;
  while (Pal.rozmiar() >= 1) {
    znak = Pal.UsunZprzodu();
    znakkop = Kopia.UsunZprzodu();
    if ( Pal.rozmiar() == 1 )
      return true;
   if (znak != znakkop )
     return false;
  }
  return false;
}
