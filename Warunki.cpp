#include "Warunki.h"


Warunki::Warunki(int _min_kom, int _max_kom){

    cout <<"Warunki: " << this <<endl;
    vector<int> warunek_ilosc_komorek{_min_kom, _max_kom};

}


Warunki::~Warunki(){}

void Warunki::zmienMax(int _max_kom){
    warunek_ilosc_komorek[1]=_max_kom;
}
void Warunki::zmienMin(int _min_kom){
    warunek_ilosc_komorek[0]=_min_kom;
}

vector<int> Warunki::podajWarunki(){

    return warunek_ilosc_komorek;
}
