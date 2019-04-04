#include "Wektor.hh"
#include "Macierz.hh"
#include <iostream>


using namespace std;


/* Przeciazenie operatora dodawania dla klasy Wektor.
 * Argumenty:
 * referencja Wektora
 * 
 * Zwraca:
 * wektor w1 który jest suma dwoch wektorow
 */

Wektor Wektor::operator + (const  Wektor & czynnik) const
{
	Wektor wynik;
	for(unsigned int ind=0; ind<ROZMIAR; ++ind)
		wynik[ind]=(*this)[ind]+czynnik[ind];
  return wynik;

}

/*
 Przeciazenie operatora odejmowania dla klasy Wektor.                                                                                                                   
 * Argumenty:                                                                                                                                                           
 * referencja Wektora odejmnik
 * Wektor                                                                                                                                                  
 *                                                                                                                                                                      
 * Zwraca:                                                                                                                                                              
 * wektor wynik który jestroznica  dwoch wektorow                                                                                                                             
 
*/

Wektor Wektor::operator - (const  Wektor &Odjemnik) const
{
  Wektor  Wynik;

  for (unsigned int Ind = 0; Ind < ROZMIAR; ++Ind) {
       Wynik[Ind] = (*this)[Ind] - Odjemnik[Ind];
  }
  return Wynik;
}


/*
 Przeciazenie operatora mnozenia dla klasy Wektor.                                                                                                                   
 * Argumenty:                                                                                                                                                           
 * liczba  
 * wektor                                                                                                                                                 
 *                                                                                                                                                                      
 * Zwraca:                                                                                                                                                              
 * wektor w1 który jestiloczynem wektora i liczby                                                                                                                             
*/
Wektor Wektor::operator *  (double Mnoznik) const
{
  Wektor  Wynik;

  for (unsigned int Ind = 0; Ind < ROZMIAR; ++Ind) {
      Wynik[Ind] = (*this)[Ind]*Mnoznik;
  }
  return Wynik;  
}

/*
 Przeciazenie operatora dzielenia dla klasy Wektor.                                                                                                                   
 * Argumenty:                                                                                                                                                           
 * liczba                                                                                                                                                   
 *                                                                                                                                                                      
 * Zwraca:                                                                                                                                                              
 * wektor w1 który jes ilorazem wektora i liczby                                                                                                                             
 */

Wektor Wektor:: operator / (double liczba) const
{
  Wektor ww;
  for(unsigned int i=0; i<ROZMIAR; i++)
    {
      ww[i]=(*this)[i]/liczba;
    }
  return ww;
}

 /* Przeciazenia operatora wyjscia <<
 * Argumenty:
 * StrWyj
 * Wektor
 * Zwraca:
 * StrWyj
 * Opis dzialania:
 * Funkcja wyswietla kolejne wartosci Wektora na ekranie
 */

ostream& operator << (ostream &StrWyj, const Wektor &ww)
{
  
    for(int i=0; i<ROZMIAR; i++)
      StrWyj<<ww[i]<<" ";
    return StrWyj;
  
}

/* Przeciazenia operatora wejscia >>
 * Argumenty:
 * StrWej
 * Wektor
 * Zwraca:
 * StrWej
 * Opis dzialania:
 * Funkcja zapisuje kolejne wartosci Wektora
 */

istream& operator >> (istream &StrWej, Wektor &ww)
{
  for(int i=0; i<ROZMIAR; i++)
    {
      StrWej>>ww[i];
    }
  return StrWej;
}

/*Przeciazenie operatora * dla mnozenia macierzy przez wektor.
 * Argumenty:
 * Macierz mm
 * Wektor
 * Zwraca:
 * Wektor bedacy iloczynem macierzy i wektora
 */

Wektor  Wektor::operator * (const Macierz mm) const
{
    Wektor pomnozony;
    for(unsigned int i=0; i<ROZMIAR; ++i)
    {
		for(unsigned int j=0; j<ROZMIAR; ++j)
        pomnozony[i]+=(mm(i, j)*(*this)[j]);
    }
    return pomnozony;
}




