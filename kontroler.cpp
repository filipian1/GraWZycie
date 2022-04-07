#include "Kontroler.h"
#include "Symulacja.h"
#include <iostream>

//konstruktor klasy kontroler
//inicjalizuje Symulacje
Kontroler::Kontroler(int _okres,int _x, int _y,int _stan_pocz, int _min_zycie,
                     int _max_zycie, int _min_smierc, int _max_smierc) : symulacjaObj( _x,  _y, _stan_pocz,  _min_zycie,
                                                                                                _max_zycie,  _min_smierc, _max_smierc)
{
    cout <<"utworzylem obiekt klasy Kontroler" <<endl;
    okresAktualizacji=_okres;
}

Kontroler::~Kontroler(){}

void Kontroler::zapiszGre(){
}
void Kontroler::wczytajGre(string file_path){
    file_path="moja_sciezka";
}
void Kontroler::startGry(){
}

void Kontroler::zmienOkresAktualizacji(int _nowy_okres){
    okresAktualizacji=_nowy_okres;
}
int Kontroler::podajOkresAktualizacji(){

    return okresAktualizacji;

}
