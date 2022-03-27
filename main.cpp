#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "MojaKlasa.h"
#include <bits/stdc++.h>


using namespace std;


template<typename T> T moj_max(T a,T b) {return (a>b)?a:b;}





void swap(int a, int b) {
int temp = a;
a = b;
 b = temp;
}

double funkcja(double (*wskaznik_na_funkcje)(double), double x)
{double wynik;
 wynik = (*wskaznik_na_funkcje)(x);}


//Definicja metod MojaKlasa

//konstruktor
CMojaKlasa::CMojaKlasa(int _a, bool _b){
    FWiek=_a;
    FCzy_moja=_b;
}


bool CMojaKlasa::Czy_moja(){
    if(FCzy_moja==true)
        return true;
    else
        return false;
}

int CMojaKlasa::Wiek(){
    cout <<"Wiek to:" << FWiek;
    return FWiek;

}

class COczko {
public:
  COczko() { kolor = "szary"; }
  string dajKolor() { return kolor; }
private:
  string kolor;
};
class CMisio {
private:
  COczko lewe;
  COczko prawe;
public:
  COczko& dajLewe() { return lewe; }
  COczko& dajPrawe() { return prawe; }
};




CMojaKlasa::~CMojaKlasa(){};


class CPunkt {
    private:
        double FX;
        double FY;

    public:
        CPunkt(double _x, double _y){
            if(_x*_x+_y*_y<=1)
            {
                cout<<"Punkt sie miesci w okręgu jednostkowym"<<endl;
                FX=_x;
                FY=_y;

            }
            else
            {   cout<<"Punkt sie nie mieci w okręgu jednostkowym"<<endl;
                throw "Blad - Punkt sie nie miesci w okręgu jednostkowym";
            }
        }
};


class CTowar {
private:
  int ilosc;
    string nazwa;
public:
  CTowar() { nazwa = ""; ilosc = 0; }
  void setNazwa(string _n) { nazwa = _n; }
  void setIlosc(int _i) { ilosc = _i; }
  void pisz() { cout << nazwa << ", ilosc: " << ilosc; }
  CTowar operator + (int const a){
  CTowar wynik;
   return wynik.ilosc=wynik.ilosc+a;
  }

};



int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//   MainWindow w;
//   w.show();
  //  return a.exec();
    CPunkt moj_punkt(0,0.1);

    CMisio misio;
    COczko l_oczko=misio.dajLewe();
    COczko p_oczko=misio.dajPrawe();
    cout<<"Lewe oczko ma kolor: " <<  l_oczko.dajKolor() << " Prawe oczko ma kolor: "<<p_oczko.dajKolor() <<endl;

   set<string> dane = {
                                "jjj",
                                "khj",
                                "bca",
                                "aaa",
                                "ddd" };

    set<string>::iterator iter = dane.begin();
    while (iter != dane.end())
    {
        std::cout << (*iter) << " \n\r";
        iter++;
    }



    int i = 0;
    int&ref_i = i;
    cout << i <<endl;      // wypisuje 0
    ref_i = 1;
    cout << i<<endl;      // wypisuje 1
    cout << ref_i<<endl;

    cout<<moj_max<short>(7,5)<<endl;
    cout<<moj_max<double>(3.1415,2.71)<<endl;
    cout<<moj_max<string>("Ania","Basia")<<endl;


    CMojaKlasa mojObiekt(25,true);

    int xxx = mojObiekt.Wiek();

    cout << "\n\r";






    return 0;
}
