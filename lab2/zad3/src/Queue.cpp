#include "Queue.hh"
#include "Node.hh"



/* Metoda klasy Kolejka
 *
 * Sprawdza czy zainicjowany obiekt typu Kolejka jest pusty
 *
 * \retval true  - jeżeli jest pusta
 * \retval false - w przeciwnym wypadku 
 */
bool Queue::empty() const
{
  if (head == NULL ) 
    return true;
  else
    return false;
}



//dodaje element na koniec kolejki
void Queue::enqueue (const int &el)
{
  Node* object = new Node;    //alokacja nowego wezła listy
  object->element = el;       //wpisz wartość do węzła
  if ( head == NULL ) {       
    head = object;            //warunek dla pierwszego elementu
    tail = object;   //głowa i ogon wskazują na pierwszy elem
  }
  else {
    tail->next = object;  //dowiązanie do następnego elementu
    tail = object;         //ogon wskazuje na ostatnio dodany elem
  }
}

//usuwa element z przodu kolejki
void Queue::dequeue()
{
  //pierwszy element z kolejki
  Node* previousNod = head;
  //głowa kolejki wskazuje na następny element z kolejki
  head = previousNod->next;
  delete previousNod; //usuniecie pierwszego elementu z kolejki
}   

//wyświetla zawartość kolejki
void Queue::Display() 
{
  Node* pointer = head;         //tymczasowy wskaźnik na pierw elem 
  while ( (pointer->next)!=NULL ) {   //dopóki nie pojawi się
    cout << pointer->element;         //NULL - koniec kolejki
    cout << endl;
    pointer = pointer->next;          // wskaż na następny elem
  }
  cout << pointer->element;         //wyświetl warość elementu
  cout << endl << endl;
}


