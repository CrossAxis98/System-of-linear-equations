#ifndef WEKTOR_HH
#define WEKTOR_HH
#include "rozmiar.h"
#include <iostream>

class Macierz;

using namespace std;

/* Klasa Wektor zawiera, tablice dla wektora oraz przeciazenia operacji arytmetycznych dla tego wektora */

class Wektor {
  double wek[ROZMIAR];

public:
  Wektor operator + (const Wektor & czynnik) const;
  Wektor operator - (const  Wektor &Odjemnik) const;
  Wektor operator * (double Mnoznik) const;
  Wektor  operator / (double liczba) const;
 /* przeciazenie operatora [] w celu dostepu do prywatnej wartosci klasy Wektor*/
  double operator [](int index) const
  {
    return wek[index];
  }

  double & operator [](int index)
  {
    return wek[index];
  }

  Wektor operator * (const Macierz mm) const;

};
/*Przeciazenie operatora wejscia*/
istream& operator >> (istream &StrWej, Wektor &ww);

/* Przeciazenia operatora wyjscia */
ostream& operator << (ostream &StrWyj, const Wektor &ww);




#endif
