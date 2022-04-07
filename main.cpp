#include <iostream>
#include "mainwindow.h"
#include <QApplication>

#include "Kontroler.h"

//#include "Symulacja.h"
//#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
//   QApplication a(argc, argv);
//   MainWindow w;
//   w.show();
//  return a.exec();


int okres_symulacji=10;
int rozmiar_x=10;
int rozmiar_y=10;
int stan_pocz=0;
int min_zycie=3;
int max_zycie=4;
int min_smierc=5;
int max_smierc=6;

cout <<"JEst  w main" <<endl;

//Komorki kom1 = Komorki(rozmiar_x,rozmiar_y,stan_pocz);
Kontroler kontrolerObj = Kontroler(okres_symulacji, rozmiar_x,  rozmiar_y, stan_pocz,  min_zycie,
                                   max_zycie,  min_smierc,  max_smierc);

cout << &kontrolerObj ;

cout << "okres to: " <<kontrolerObj.podajOkresAktualizacji();

kontrolerObj.symulacjaObj.obliczNastepnyKrokSymulacji();

//kom1.pokazKomorki();
////0 wiersz i 1 kolumna
//bool stanA= kom1.podajStan(1,0);
//kom1.aktualizujStan(1,0,0);

//bool stanB=kom1.podajStan(1,0);

//cout <<"StanA: " << stanA << " stanB: " << stanB <<endl;

//kom1.pokazKomorki();

//cout << "K1 stan:" << k1.podajStan() << endl;
//cout << "K1 pozycja1:"<< " x: "<< p1[0] <<" y: "<<  p1[1] << endl;
//cout << "K1 pozycja2:"<< " x: "<< *p1 <<" y: "<< *(p1+1) << endl;



//cout << "K2 stan:" << k2.podajStan() << endl;
//cout << "K2 pozycja:"<< " x: "<< p2[0] <<" y: "<<p2[1]<< endl;
//cout << "K2 pozycja2:"<<" x: "<<  *p2 <<" y: "<<*(p2+1)  << endl;


//k2.aktualizujStan(true);
//k1.aktualizujStan(false);


//cout << "K1 stan:" << k1.podajStan() << endl;
//cout << "K1 pozycja1:"<< " x: "<< p1[0] <<" y: "<<  p1[1] << endl;
//cout << "K1 pozycja2:"<< " x: "<< *p1 <<" y: "<< *(p1+1) << endl;

//cout << "K2 stan:" << k2.podajStan() << endl;
//cout << "K2 pozycja:"<< " x: "<< p2[0] <<" y: "<<p2[1]<< endl;
//cout << "K2 pozycja2:"<<" x: "<<  *p2 <<" y: "<<*(p2+1)  << endl;



return 0;
}
