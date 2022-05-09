#include <iostream>
#include<iomanip>
#include <vector>
#include <fstream>
#include "Bilet.h"
#include "Lot.h"
#include "Rejs.h"
#include "Laczony.h"

using namespace std;

template <class T>

class Baza
{
public:
    vector<T*> baza;
    vector<T*> dostepne;

    T* operator +=(T* element)
    {
        baza.push_back(element);
    }

    T* operator -=(T* element)
    {
        baza.erase(element);
    }

    T* dodaj_lot(fstream& plik)
    {
        string rodzaj, start, koniec, data, godzina,firma;
        int nr_rezerwacji,bramka;
        float cena;
        plik>>rodzaj>>nr_rezerwacji>>start>>koniec>>data>>godzina>>cena>>firma>>bramka;
        T* element = new Lot(rodzaj,nr_rezerwacji,start,koniec,data,godzina,cena,firma,bramka);
        return element;
    }

    T* dodaj_rejs(fstream& plik)
    {
        string rodzaj, start, koniec, data, godzina, nazwa_statku;
        int nr_rezerwacji;
        float cena;
        plik>>rodzaj>>nr_rezerwacji>>start>>koniec>>data>>godzina>>cena>>nazwa_statku;
        T* element = new Rejs(rodzaj,nr_rezerwacji,start,koniec,data,godzina,cena,nazwa_statku);
        return element;
    }

    T* dodaj_laczony(fstream& plik)
    {
        vector <T> bil;
        int ile, nr;
        string rodzaj;
        plik >> nr >> ile;
        for (int i = 0; i < ile; i++)
        {
            plik >> rodzaj;

            if (rodzaj == "Lot")
                bil += dodaj_lot(plik);

            else if (rodzaj == "Rejs")
                bil += dodaj_rejs(plik);
        }

        T* element = new Laczony(bil,nr);
        return element;
    }


    void wczytaj_plik(vector <T> v, string plik)
    {
        ifstream plik(fstream& plik);
        string rodzaj;

        if(plik.good())
        {
            while(!plik.eof())
            {
                plik>>rodzaj;
                if(rodzaj=="Lot")
                {
                    v+=dodaj_lot(plik);
                }
                else if(rodzaj=="Rejs")
                {
                    v+=dodaj_rejs(plik);
                }
                else if(rodzaj=="Laczony")
                {
                    v+=dodaj_laczony(plik);
                }
            }
        }
        plik.close();
    }
    void zapisz_pliki(string p)
    {
        fstream plik;
        plik.open(p,ios::out);
        int rozmiar=baza.size();

        for(int i=0; i<rozmiar; i++)
        {
            baza[i]->zapisz(plik);
        }
        plik.close();
    }
    void wyswietl(vector <T*> v)
    {
        int rozmiar=v.size();
        if(rozmiar==0)
            cout<<"Nic tu nie ma."<<endl;
        for(int i=0; i<rozmiar; i++)
        {
            v[i]->wyswietl();
        }
    }

    void dodaj()
    {
        int nr;
        cout<<"Mamy do dyspozycji takie bilety. Podaj numer rezerwacji biletu, ktory wybierasz."<<endl;
        wyswietl(dostepne);
        cin>>nr;
        auto it = find(dostepne, nr);
        //auto it = find(dostepne.begin(), dostepne.end(), nr);
        if(it != dostepne.end())
        {
            baza+=it;
        }
        else
        {
            cout<<"Nie ma takiej podrozy."<<endl;
        }


    }

    void usun()
    {
        int n;
        cout<<"Podaj numer rezerwacji: "<<endl;
        cin>>n;

        auto it = find(baza.begin(), baza.end(), n);
        if(it != baza.end())
        {
            baza-=it;
        }
        else
        {
            cout<<"Nie masz takiej rezerwacji."<<endl;
        }
    }



    void menu()
    {
        int n;
        while(n!=4)
        {
            cout<<"Wybierz opcje: "<<endl;
            cout<<"1. Zarezerwuj podroz."
                <<endl<<"2.Anuluj rezerwacje."
                <<endl<<"3.Wyswietl moje rezerwacje."
                <<endl<<"4.Zakoncz."<<endl;
            cin>>n;

            switch(n)
            {
            case 1:
                dodaj();
                break;
            case 2:
                usun();
                break;
            case 3:
                wyswietl(baza);
                break;
            default:
                cout<<"Wybierz numer od 1 do 4."<<endl;
                break;
            }
        }
    }



};


