#include <iostream>
#include "Symulacja.h"
#include "Komorki.h"
#include "Warunki.h"

using namespace std;

Symulacja::Symulacja(int _x, int _y,int _stan_pocz, int _min_zycie,
                     int _max_zycie, int _min_smierc, int _max_smierc)
    :zycieWarunkiObj(_min_zycie,_max_zycie),
     smiercWarunkiObj(_min_smierc, _max_smierc) {

    //zerowy krok symulacji
    krok_symulacji=0;
//    this->krok_syumulacji=0;
    //inicjalizacja komorek
    cout<<"Symulacja konstruktor" << endl;

    wymiar_xy.push_back(_x);
    wymiar_xy.push_back(_y);

    //utworzenie tablicy komorek
    for(int i=0;i<wymiar_xy[1];i++)
    {
        vector<int> wiersz;
        for(int j=0;j<wymiar_xy[0];j++)
        {
          wiersz.push_back(_stan_pocz);
        }

      tablica_komorek.push_back(wiersz);
    }
    //status poczatkowy symulacji
    status_symulacji=false;


}


Symulacja::~Symulacja(){}

void Symulacja::startSymulacji(){
    status_symulacji=true;
}

void Symulacja::stopSymulacji(){
    status_symulacji=false;
}

void Symulacja::resetSymulacji(){
    status_symulacji=false;
}

void Symulacja::obliczNastepnyKrokSymulacji(){

    cout << "Obliczam krok symulacji nr: " << krok_symulacji << endl;
    int kolumny = wymiar_xy[0];
    int wiersze = wymiar_xy[1];
    vector<vector< int >> przyszle_komorki;
    if (krok_symulacji==0){
        przyszle_komorki=tablica_komorek;
    }


    for(int w=1;w<wiersze-1;w++){
        for(int k=1;k<kolumny-1;k++){

            //zliczanie zywych sasiadow dla kazdej komorki
            int zywi_sasiedzi=0;
            for (int i = -1; i < 2; i++)
                for (int j = -1; j < 2; j++)
                    zywi_sasiedzi += tablica_komorek[w + i][k + j];

            cout << "Kom: "<< w*(wiersze-1)+k << " Zywi sasiedzi " << zywi_sasiedzi << endl;

            //odjecie komorki centralnej
            zywi_sasiedzi -= tablica_komorek[w][k];

            //Sprawdzanie warunkow przezycia:

            //Warunki smierci komorki
            if ((tablica_komorek[w][k] == 1) && ((zywi_sasiedzi < 2)|| (zywi_sasiedzi > 3)))
                przyszle_komorki[w][k] = 0;

            //Narodziny komorki
            else if ((tablica_komorek[w][k] == 0) && (zywi_sasiedzi == 3))
                przyszle_komorki[w][k] = 1;

            //Brak zmian
            else
                przyszle_komorki[w][k] = tablica_komorek[w][k];
        }
    }


    //inkrementacja kroku symulacji
    krok_symulacji++;





}
bool Symulacja::podajStatusSymulacji(){

    return status_symulacji;
}

int Symulacja::podaj_krok_symulacji(){
    return krok_symulacji;

}
