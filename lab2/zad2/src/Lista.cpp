#include "Lista.hh"
#include "Wezel.hh"



/* Metoda klasy Lista
 *
 * Sprawdza czy zainicjowany obiekt typu Lista jest pusty
 *
 * \retval true  - jeżeli jest pusta
 * \retval false - w przeciwnym wypadku 
 */
bool Lista::czyPusta() const
{
  if (glowa == NULL ) 
    return true;
  else
    return false;
}



//dodaje element do listy jednokierunkowej z przodu
void Lista::DodajNapocz (const int &el)
{
  Wezel* obiekt = new Wezel;    //alokacja nowego wezła listy
  
  if ( glowa == NULL ) {
    ogon = obiekt;
  }

  obiekt->element = el;        //wpisz nowy element do węzła listy  
  obiekt->nastepny = glowa;   //wskazanie na następny element       
  glowa = obiekt;            //niech glowa pokazuje na nowy obiekt
  cout << endl;
}

//dodaje element do listy jednokierunkowej z tyłu
void Lista::DodajZtylu (const int &el)
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
}

//usuwa element z przodu listy
void Lista::UsunZprzodu()
{
  //pierwszy element z listy
  Wezel* usuwanyWezel = glowa;
  //głowa listy wskazuje na następny element z listy
  glowa = usuwanyWezel->nastepny;
  delete usuwanyWezel; //usuniecie pierwszego elementu z listy
}   


//wyświetla zawartość listy jesnokierunkowej
void Lista::Wyswietl() 
{
  Wezel* wskaz = glowa;
  while ( (wskaz->nastepny)!=NULL ) {
    cout << wskaz->element;
    cout << endl;
    wskaz = wskaz->nastepny;
  }
  cout << wskaz->element;
  /*if ( wskaz->nastepny != NULL ) {
    cout << ogon->element;
    }*/
  cout << endl << endl;
 
}


