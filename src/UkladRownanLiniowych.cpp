#include "UkladRownanLiniowych.hh"

/* Przeciazenia operatora wejscia >>
 * Argumenty:
 * StrWej
 * UklRownanLiniowych
 * Zwraca:
 * StrWej
 * Opis dzialania:
 * Funkcja zapisuje kolejne wartosci Ukladu
 */

istream& operator >> (istream &StrWej, UkladRownanLiniowych &UklRown)
{
 Macierz macie;
 Wektor wekt;
 StrWej>>macie;
 StrWej>>wekt;
 UklRown.ustawWektor(wekt);
  UklRown.ustawMacierz(macie);
     return StrWej;
 }

 /* Przeciazenia operatora wyjscia <<
 * Argumenty:
 * StrWyj
 * UklRownanLiniowych
 * Zwraca:
 * StrWyj
 * Opis dzialania:
 * Funkcja wyswietla kolejne wartosci Ukladu na ekranie
 */

ostream& operator << (ostream &StrWyj, const UkladRownanLiniowych &UklRown)
{		StrWyj<<"Macierz A^T: "<<endl;
     StrWyj<<UklRown.przekazMac()<<endl;
     StrWyj<<"Wektor wyrazow wolonych b: "<<endl;
     StrWyj<<UklRown.przekazWek()<<endl;

return StrWyj;
 }


/*Obliczanie epsilona.
 * Argumenty:
 * UR1
 * Zwraca:
 * Wektor bledu
 */

Wektor UkladRownanLiniowych::epsilon()
{
	Wektor ee;
	Macierz bb;
	bb=macierzA.transponuj();
	ee=this->wynik()*bb-this->przekazWek();
	return ee;

}

/*Rozwiazywanie ukladu rownan.
 * Argumenty:
 * Ur1
 * Zwraca:
 * wektor bedacy wynikiem {x1, x2, x3}

*/
Wektor UkladRownanLiniowych::wynik()
{
	Wektor wynik;
	Macierz bb=macierzA.transponuj();
	double wyznacznik=bb.ObliczWyznacznik();
	for(int i=0; i<ROZMIAR; ++i)
	{
	for(int j=0; j<ROZMIAR; ++j)
	bb(j, i)=WyrWolne[j];

	wynik[i]=bb.ObliczWyznacznik()/wyznacznik;
	bb=macierzA.transponuj();

}
	return wynik;
}







