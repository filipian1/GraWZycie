#include "Warunki.h"

//KONSTRUKTOR
Warunki::Warunki(int _min_kom, int _max_kom){


    warunekIloscKomorek_.push_back(_min_kom);
    warunekIloscKomorek_.push_back(_max_kom);

//    cout <<"rozmiar w konstruktorze: " <<  warunekIloscKomorek_.size() << endl;
//    cout << "MIN i MAX: " << warunekIloscKomorek_[0] << warunekIloscKomorek_[1] <<endl;
}

//DESTRUKTOR
Warunki::~Warunki(){}


int Warunki::testWarunki(){
    return 3;
}
const vector<int> &Warunki::warunekIloscKomorek() const
{
//    cout << "Wewnatrz warunki Ilosc Komorek" <<endl;
//    cout <<"rozmiar" << warunekIloscKomorek_.size() << endl;
    return warunekIloscKomorek_;
}

void Warunki::setWarunekIloscKomorek(const vector<int> &newWarunekIloscKomorek)
{
    warunekIloscKomorek_ = newWarunekIloscKomorek;
}
