#include "Bilet.h"

using namespace std;

class Rejs : public Bilet
{
public:
    string nazwa_statku;
    Rejs(string, int, string,string,string,string,float,string);
    virtual void zapisz(fstream&);
    virtual void wyswietl();
};
