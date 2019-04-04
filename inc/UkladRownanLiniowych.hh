#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH
#include "Wektor.hh"
#include "Macierz.hh"
#include <iostream>


/*Klasa Uklad Rownan dla zmiennych Macierz oraz Wektor */
class UkladRownanLiniowych {

  Wektor WyrWolne;
  Macierz macierzA;

   public:

  /*Funkcja przekazujaca prywatnym argumentom pobrane dane */

  Wektor  ustawWektor(Wektor wek)
  {
	  WyrWolne=wek;
	  return WyrWolne;
  }
  Macierz  ustawMacierz(Macierz mm)
  {
	  macierzA=mm;
	  return macierzA;
  }
  /*Funkcje zwracajace prywatne dane dla operacji przeciazenia wyswietlania */
  Macierz przekazMac() const
  {
	  return macierzA;
  }
  Wektor przekazWek() const
  {
	  return WyrWolne;
  }
  /*Metody potrzebne do wykonania zadanych obliczen */
    Wektor epsilon();
    Wektor wynik();
};

/* Przeciazenia operatora wejscia */
istream& operator >> (istream &StrWej, UkladRownanLiniowych &UklRown);
/* Przeciazenia operatora wyjscia */
ostream& operator << (ostream &StrWyj, const UkladRownanLiniowych &UklRown);


#endif
