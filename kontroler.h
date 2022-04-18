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
    void stopGry();
    Symulacja symulacjaObj;


private:



};


#endif // KONTROLER_H
