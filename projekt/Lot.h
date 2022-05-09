#include "Bilet.h"

using namespace std;

class Lot : public Bilet
{
    public:
    string firma;
    int bramka;
    Lot(string, int, string,string,string,string,float,string,int);
    virtual void zapisz(fstream&);
    virtual void wyswietl();
};
