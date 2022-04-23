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
    void loadTablicaKomorek(string);
    void saveTablicaKomorek(string);
    void initTablicaKomorek();
    void losowyStanPoczatkowy();

    void obliczNastepnyKrokSymulacji();

    bool statusSymulacji() const;
    void setStatusSymulacji(bool newStatusSymulacji);
    int  krokSymulacji() const;
    void setKrokSymulacji(int);
    void wczytajTablica_komorek();
    void printTablicaKomorek();
//  const vector<vector<int> > &tablicaKomorek() const;
//  void setTablicaKomorek(const vector<vector<int> > &newTablicaKomorek);

    void setOkresAktualizacji(int);
    int okresAktualizacji();
    Warunki zycieWarunkiObj_;
    Warunki smiercWarunkiObj_;
    vector<vector< int >> tablicaKomorek_;
    vector<int> wymiarXY_;


private:
    bool statusSymulacji_;
    int krokSymulacji_;
    int okresAktualizacji_;
    const int stanPoczatkowy_=0;
//    vector<int> wymiarXY_;


};

#endif // SYMULACJA_H
