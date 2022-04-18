#include "Kontroler.h"
#include "Symulacja.h"

#include <iostream>

//konstruktor klasy kontroler
//inicjalizuje Symulacje
Kontroler::Kontroler(int _okres,int _x, int _y,int _stan_pocz, int _min_zycie, int _max_zycie, int _min_smierc, int _max_smierc)
          : symulacjaObj(_okres,_x,  _y, _stan_pocz,  _min_zycie, _max_zycie,  _min_smierc, _max_smierc)
{
//    cout <<"utworzylem obiekt klasy Kontroler" <<endl;
}

Kontroler::~Kontroler(){
}

void Kontroler::zapiszGre(){
}

void Kontroler::wczytajGre(string file_path){
    int _statusSym= symulacjaObj.statusSymulacji();

    //wczytanie gry gdy symulacja jest zastopowana
    if (_statusSym==false){
        symulacjaObj.initTablicaKomorek(file_path);
    }
}

void Kontroler::startGry(){
    //uruchomienie symulacji
    symulacjaObj.setStatusSymulacji(true);
    //trwa symulacja
    symulacjaObj.trwaSymulacja();
}

void Kontroler::stopGry(){
    //stop symulacji
    symulacjaObj.setStatusSymulacji(false);
}


