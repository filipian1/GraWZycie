#ifndef ZLOZONAFORMAZYCIA_H
#define ZLOZONAFORMAZYCIA_H

using namespace std;
#include "formazycia.h"



class ZlozonaFormaZycia : public FormaZycia
{

public:
    ZlozonaFormaZycia(string nazwa ="",string filePath="");
    void setRozmiarXY(int,int);
    int* rozmiarXY();
    vector<vector<int>> tabFormaZycia_;

private:
    int rozmiarXY_[SIZE];
    int test[SIZE];
    int dsfdfw;

};

#endif // ZLOZONAFORMAZYCIA_H
