#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include "Wektor.hh"
#include <iostream>

using namespace std;


/* Klasa Macierz, zawiera tablice do macierzy */

class Macierz {

  Wektor mac[ROZMIAR];

public:

/* przeciazenie operatora () w celu dostepu do prywatnej wartosci klasy Macierz*/
  double operator () (int wiersz, int kolumna) const
    {
        return mac[wiersz][kolumna];
    }

    double & operator () (int wiersz, int kolumna)
    {
        return mac[wiersz][kolumna];
    }
    /*Deklaracje Metod dla klasy Macierz*/
	Macierz transponuj();
	double ObliczWyznacznik();
	double WykonajElimGaussaiObliczWyznacznik();
	Macierz SprowadzdoMacierzyTrojkatnej();
	double ObliczElementyPrzekatnej();


};
/* Przeciazenia operatora wejscia */
istream& operator >> (istream &StrWej, Macierz &mm);


/* Przeciazenia operatora wyjscia */
ostream& operator << (ostream &StrWyj, const Macierz &mm);


#endif
