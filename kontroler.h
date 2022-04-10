#ifndef KONTROLER_H
#define KONTROLER_H

#include <iostream>
using namespace std;
#include "Symulacja.h"


class Kontroler{
public:
    Kontroler(int ,int, int, int, int, int, int,int);
    ~Kontroler();
    void zapiszGre();
    void wczytajGre(string);
    void startGry();
    void zmienOkresAktualizacji(int);
    int podajOkresAktualizacji();
    Symulacja symulacjaObj;

private:
    int okresAktualizacji;


};


#endif // KONTROLER_H
