#ifndef WARUNKI_H
#define WARUNKI_H

#include <iostream>
#include <vector>

using namespace std;


class Warunki{
public:
    Warunki(int, int);
    ~Warunki();
    void zmienMax(int);
    void zmienMin(int);
    vector<int> podajWarunki();
private:
    vector<int> warunek_ilosc_komorek;
};

#endif //WARUNKI_H
