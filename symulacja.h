#ifndef SYMULACJA_H
#define SYMULACJA_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>

#include "Warunki.h"

class Symulacja{
public:
    Symulacja(int, int, int, int, int, int,int);
    Symulacja();
    ~Symulacja();
    void startSymulacji();
    void stopSymulacji();
    void resetSymulacji();
    void initTablicaKomorek(string);
    void obliczNastepnyKrokSymulacji();

    bool statusSymulacji() const;
    void setStatusSymulacji(bool newStatusSymulacji);
    int  krokSymulacji() const;
    void wczytajTablica_komorek();
    void printTablica_komorek();
    const vector<vector<int> > &tablicaKomorek() const;
    void setTablicaKomorek(const vector<vector<int> > &newTablicaKomorek);
    Warunki zycieWarunkiObj;
    Warunki smiercWarunkiObj;

private:
    bool statusSymulacji_;
    int krokSymulacji_;
    vector<int> wymiarXY_;
    vector<vector< int >> tablicaKomorek_;


};

#endif // SYMULACJA_H
