#ifndef WARUNKI_H
#define WARUNKI_H

#include <iostream>
#include <vector>

using namespace std;


class Warunki{
public:
    Warunki(int, int);
    ~Warunki();
    const  vector<int> &warunekIloscKomorek() const;
    int testWarunki();
    void setWarunekIloscKomorek(const vector<int> &newWarunekIloscKomorek);

private:
    vector<int> warunekIloscKomorek_;
};

#endif //WARUNKI_H
