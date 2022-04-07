#ifndef SYMULACJA_H
#define SYMULACJA_H

#include "Warunki.h"
#include <vector>


class Symulacja{
public:
    Symulacja(int, int, int, int, int, int,int);
    Symulacja();
    ~Symulacja();
    void startSymulacji();
    void stopSymulacji();
    void resetSymulacji();
    void obliczNastepnyKrokSymulacji();
    bool podajStatusSymulacji();
    int podaj_krok_symulacji();


private:
    bool status_symulacji;
    int krok_symulacji;
    vector<int> wymiar_xy;
    vector<vector< int >> tablica_komorek;
    Warunki zycieWarunkiObj;
    Warunki smiercWarunkiObj;


};

#endif // SYMULACJA_H
