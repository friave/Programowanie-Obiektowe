#include "Bilet.h"
#include<vector>
#include<memory>

using namespace std;

class Laczony : public Bilet
{
public:
    vector<Bilet*> bilety;
    Laczony(vector<Bilet*>,int);
    virtual void zapisz(fstream&);
    virtual void wyswietl();

};
