#ifndef FORMAZYCIA_H
#define FORMAZYCIA_H

#include <iostream>
#include <vector>
using namespace std;

class FormaZycia
{
public:
    FormaZycia(string nazwa ="",string filePath="");
    ~FormaZycia();
    static const int SIZE= 2;
    void setPozycjaXY(int, int);
    int* pozycjaXY();

    void setNazwa(string);
    void setSciezkaDoPliku(string);
    vector<int> tabFormaZycia_;

    void setRozmiarXY(int);
    int rozmiarXY();


protected:

    int pozycjaXY_[SIZE];
    int rozmiarXY_;
    string nazwa_;
    string sciezkaDoPliku_;

};

//template<typename T> class FormaZycia {
//    public:
//        static const size_t N;
//    private:
//        T _rep[N];
//        size_t _top;
//    public:
//        FormaZycia():_top(0) {

//        }
//        void push(T val){
//            _rep[_top++]=val;
//        }
//        T pop(){
//            return _rep[--_top];
//        }
//        bool is_empty(){
//            return (_top==0);
//        }
//};

//template<size_t N,typename T> T rysujSzablon(T *a, int wymX, int wymY) {

//if(N==1)
//{
//    T tab[wymX];
//    return tab;
//}
//else if(N==2)
//{
//    T tab[wymX][wymY];
//    return tab;
//}
//};


#endif // FORMAZYCIA_H
