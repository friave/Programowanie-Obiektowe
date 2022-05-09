#include "Lot.h"


using namespace std;

Lot::Lot(string r,int n, string s,string k,string d,string g,float c,string f, int b):Bilet(n,s,k,d,g,c)
{
    rodzaj="Lot";
    firma=f;
    bramka=b;
}

void Lot::zapisz(fstream& plik)
{
        plik<<rodzaj<<" "<<nr_rezerwacji<<" "<<start<<" "<<koniec<<" "<<data<<" "<<godzina<<" "<<cena<<" "<<firma<<" "<<bramka<<endl;
}

void Lot::wyswietl()
{
        cout<<rodzaj<<" "<<nr_rezerwacji<<" "<<start<<" "<<koniec<<" "<<data<<" "<<godzina<<" "<<cena<<" "<<firma<<" "<<bramka<<endl;
}





