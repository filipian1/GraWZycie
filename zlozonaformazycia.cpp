#include "zlozonaformazycia.h"
using namespace std;


ZlozonaFormaZycia::ZlozonaFormaZycia(string nazwa,string filePath)
{
    nazwa_=nazwa;
    sciezkaDoPliku_=filePath;

    cout << "Utworzono nowa zlozona forme zycia o nazwie: " << nazwa;

}

void ZlozonaFormaZycia::setRozmiarXY(int newRozX, int newRozY)
{
    rozmiarXY_[0]=newRozX;
    rozmiarXY_[1]=newRozY;
}

int *ZlozonaFormaZycia::rozmiarXY()
{
    return rozmiarXY_;
}
