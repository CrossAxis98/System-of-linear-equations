#include "Macierz.hh"
#include <iostream>


using namespace std;

/* Przeciazenia operatora wyjscia <<
 * Argumenty:
 * StrWyj
 * Macierz mm
 * Zwraca:
 * StrWyj
 * Opis dzialania:
 * Funkcja wyswietla kolejne wartosci Macierzy na ekranie
 */

ostream& operator << (ostream &StrWyj, const Macierz &mm)
{
    for(int x=0; x<ROZMIAR; ++x)
        {
        for(int y=0; y<ROZMIAR; ++y)
        StrWyj<<mm(x, y)<<" ";

        StrWyj<<endl;
        }
return StrWyj;
}

/* Przeciazenia operatora wejscia >>
 * Argumenty:
 * StrWej
 * Macierz mm
 * Zwraca:
 * StrWej
 * Opis dzialania:
 * Funkcja zapisuje kolejne wartosci Macierzy.
 */

istream & operator>>(istream & StrWej, Macierz & mm)
{
    for(int x=0; x<ROZMIAR; ++x)
    {
        for(int y=0; y<ROZMIAR; ++y)
    {
        StrWej>>mm(x,y);

    }
}
    return StrWej;
}



/*
Metoda transponujaca macierz.
 * Argumenty:
 * Macierz
 * Zwraca:
 * Macierz transponowana.
 */

Macierz Macierz::transponuj()
{
	Macierz tmp=(*this);
	for(int i=0; i<ROZMIAR; i++)
		for(int j=0; j<ROZMIAR; j++)
		tmp(i, j)=(*this)(j, i);

	return tmp;


}



double Macierz::ObliczWyznacznik(){                                // Funkcja obliczajaca wyznacznik zawierajaca funkcje pomocnicze
Macierz tmp = (*this);
return tmp.WykonajElimGaussaiObliczWyznacznik();
}

double Macierz::WykonajElimGaussaiObliczWyznacznik(){
	Macierz bb=(*this);
bb=SprowadzdoMacierzyTrojkatnej();
return bb.ObliczElementyPrzekatnej();
}

Macierz Macierz::SprowadzdoMacierzyTrojkatnej(){
	Macierz tmp=*this;
  double x;
  for(int i=0;i<(ROZMIAR-1);i++)
    {
      for(int j=i+1;j<ROZMIAR;j++)
    {
      x=tmp.mac[j][i]/tmp.mac[i][i];
      for(int k=0;k<ROZMIAR;k++)
        {
          tmp.mac[j][k]-=x*tmp.mac[i][k];
        }
    }
    }
	return tmp;

}


double Macierz::ObliczElementyPrzekatnej(){
double Wynik = 1;
for(int i=0; i<ROZMIAR; i++){
Wynik *= (*this)(i,i);
}
return Wynik;
}
