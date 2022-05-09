#include"Laczony.h"

using namespace std;

Laczony::Laczony(vector<Bilet*> b,int n):Bilet(n,s,k,d,g,c)
{
    rodzaj="Laczony";
    bilety=b;
}

void Laczony::wyswietl()
{
    for(unsigned i=0;i<bilety.size();i++)
    {
        bilety[i]->wyswietl();
    }
}

void Laczony:zapisz(fstream& plik)
{
    plik<<rodzaj<<" "<<nr_rezerwacji<<" "<<bilety.size()<<endl;
    for(unsigned i=0;i<bilety.size();i++)
    {
        bilety[i]->zapisz(plik);
    }
}
