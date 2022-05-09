#include <iostream>
#include <fstream>
#pragma once

using namespace std;

class Bilet
{
public:
    int nr_rezerwacji;
    float cena;
    string rodzaj, start, koniec, data, godzina;
    Bilet(int, string,string,string,string,float);
    virtual void zapisz(fstream&)=0;
    virtual void wyswietl()=0;
};
