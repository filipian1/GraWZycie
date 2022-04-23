#include "formazycia.h"
using namespace std;


FormaZycia::FormaZycia(string nazwa, string filePath)
{
    nazwa_=nazwa;
    sciezkaDoPliku_=filePath;
    cout << "Utworzono nowa forme zycia o nazwie: " << nazwa;
}

FormaZycia::~FormaZycia()
{
}

void FormaZycia::setPozycjaXY(int newX, int newY)
{
    pozycjaXY_[0]=newX;
    pozycjaXY_[1]=newY;
}

int *FormaZycia::pozycjaXY()
{
    return pozycjaXY_;
}

void FormaZycia::setNazwa(string newNazwa)
{
    nazwa_=newNazwa;
}

void FormaZycia::setSciezkaDoPliku(string file_path)
{
    sciezkaDoPliku_=file_path;
}

void FormaZycia::setRozmiarXY(int newRozmiar)
{
    rozmiarXY_=newRozmiar;
}

int FormaZycia::rozmiarXY()
{
    return rozmiarXY_;
}
