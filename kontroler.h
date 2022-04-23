#ifndef KONTROLER_H
#define KONTROLER_H

#include <iostream>
using namespace std;
#include "Symulacja.h"
#include "formazycia.h"
#include "zlozonaformazycia.h"



class Kontroler{
public:
    Kontroler(int ,int, int, int, int, int,int);
    ~Kontroler();
    void zapiszGre(string);
    void wczytajGre(string);
    void startGry();
    void resetGry();
    void pauzaGry();
    void losowyStanPoczatkowy();
    void rysujFormeZycia(FormaZycia);
    FormaZycia wczytajFormeZycia(string, string);
    void rysujZlozonaFormeZycia(ZlozonaFormaZycia);
    ZlozonaFormaZycia wczytajZlozonaFormeZycia(string, string);
    Symulacja symulacjaObj_;

private:




};


#endif // KONTROLER_H
