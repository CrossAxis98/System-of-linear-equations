#include <iostream>
#include <cmath>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"

using namespace std;


void petlarozw()
{
	for(int i=0; i<ROZMIAR; ++i)
	cout<<"x"<<i+1<<" ";
}


int main()
{
    UkladRownanLiniowych UR1;
    cout << endl << " Start programu " << endl << endl;
    cin>>UR1;
    cout<<UR1;
    cout<<"Rozwiazanie x= {";
    petlarozw();
    cout<<"}"<<endl;
    cout<<UR1.wynik()<<endl;

  return 0;
}
