#include "Rejs.h"


using namespace std;

Rejs::Rejs(string r, int n, string s,string k,string d,string g,float c,string ns):Bilet(n,s,k,d,g,c)
{
    rodzaj="Rejs";
    nazwa_statku=ns;
}


void Rejs::zapisz(fstream& plik)
{
        plik<<rodzaj<<" "<<nr_rezerwacji<<" "<<start<<" "<<koniec<<" "<<data<<" "<<godzina<<" "<<cena<<" "<<nazwa_statku<<endl;
}

void Rejs::wyswietl()
{
        cout<<rodzaj<<" "<<nr_rezerwacji<<" "<<start<<" "<<koniec<<" "<<data<<" "<<godzina<<" "<<cena<<" "<<nazwa_statku<<endl;
}
