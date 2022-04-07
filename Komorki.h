#ifndef KOMORKI_H
#define KOMORKI_H

#include <iostream>
#include <vector>

using namespace std;

class Komorki{
public:
    Komorki(int,int,int);
    ~Komorki();
    bool podajStan(int,int);
    void aktualizujStan(int,int,int);
    void pokazKomorki();
    vector<int> podajRozmiaryXY();
private:
    //rozmiary tablicy x i y
    vector<int> wymiar_xy;
    //tablica komorek
    vector<vector< int >> tablica_Komorek;

};


#endif // KOMORKI_H
