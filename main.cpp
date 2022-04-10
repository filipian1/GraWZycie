#include <iostream>
#include <string>
#include "mainwindow.h"
#include <QApplication>
#include "Kontroler.h"
#include "Symulacja.h"

//#include "Symulacja.h"
//#include <bits/stdc++.h>

using namespace std;


vector <int> interfejsTerminal(){
    vector <int> interfejsTerminal_;

    interfejsTerminal_.push_back(3);
    cout << "Witaj, to jest gra w Zycie" << endl;
    cout << "Gra w zycie zostala stworzona przez brytyjskiego matematyka Johna Conwella w 1970 roku." << endl;
    cout << "Zasady" << endl;
    cout << "Gra w zycie, a w zasadzie symulator “zycia” toczy sie na planszy podzielonej na kwadratowe komorki." << endl;
    cout << "Kazda komorka posiada osiem komorek sąsiadujących - komorki przylegające do niej bokami i rogami. " << endl;
    cout << "Kazda komorka moze znajdowac sie w jednym z dwoch stanow: moze byc albo „zywa” (zapalona), albo „martwa” (zgaszona)." << endl;
    cout << "Stany komorek zmieniają sie co pewien okres czasu." <<endl;
    cout << "Stan wszystkich komorek w chwili t-1 jest uzywany do obliczenia stanu wszystkich komorek w chwili t." << endl;
    cout << "W podstawowej wersji, gra posiada w tylko dwie główne reguły:" << endl;
    cout << "-Martwa komórka, która ma dokładnie 3 żywych sąsiadów, staje się żywa w następnej chwili czasu (rodzi się)" << endl;
    cout << "Żywa komórka z 2 albo 3 żywymi sąsiadami pozostaje nadal żywa; przy innej liczbie sąsiadów umiera (z „samotności” albo „zatłoczenia”)" << endl;
    cout << "..." << endl;
    cout << "..." << endl;
    cout << "Podaj warunki poczatkowe odzielone spacjami, na koniec podaj znak 'X':" << endl;
    cout << "Podaj: okres poczatkowy, rozmiar_planszy_x, rozmiar_planszy_y, min_zycie, max_zycie, min_smierc, max_smierc" << endl;


    cout <<"Podane przez ciebie warunku to:" <<endl;
    cout <<" okres_symulacji=10" <<endl;
    cout <<" rozmiar_x=10" <<endl;
    cout <<" rozmiar_y=10" <<endl;
    cout <<" stan_pocz=0" <<endl;
    cout <<" min_zycie=3" <<endl;
    cout <<" max_zycie=3" <<endl;
    cout <<" min_smierc=2" <<endl;
    cout <<" max_smierc=3" <<endl;
    cout << "START SYMULACJI" << endl;
    cout << "..." << endl;
    cout << endl;
    return interfejsTerminal_;

}

int main(int argc, char *argv[])
{
//   QApplication a(argc, argv);
//   MainWindow w;
//   w.show();
//  return a.exec();

bool czy_gui = false;

if (czy_gui ==false)
{
   vector <int> myinterfejsTerminal= interfejsTerminal();
}

int okres_symulacji=10;
int rozmiar_x=10;
int rozmiar_y=10;
int stan_pocz=0;
int min_zycie=3;
int max_zycie=3;
int min_smierc=2;
int max_smierc=3;
string _plik_init="D:\\Users\\285732\\Documents\\WORKSPACES\\Qt\\GraWZycie\\Pliki\\tablica_init.csv";
//string _plik_init="..\\..\\GraWZycie\\Pliki\\tablica_init.csv";

//cout <<"Jest  w main" <<endl;

//Komorki kom1 = Komorki(rozmiar_x,rozmiar_y,stan_pocz);
Kontroler kontrolerObj = Kontroler(okres_symulacji, rozmiar_x,  rozmiar_y, stan_pocz,  min_zycie,
                                   max_zycie,  min_smierc,  max_smierc);



//cout << &kontrolerObj;
//cout << "okres to: " <<kontrolerObj.podajOkresAktualizacji() << endl;

kontrolerObj.symulacjaObj.initTablicaKomorek(_plik_init);

kontrolerObj.symulacjaObj.startSymulacji();


int i=0;
while (kontrolerObj.symulacjaObj.statusSymulacji()){

    kontrolerObj.symulacjaObj.obliczNastepnyKrokSymulacji();
    i++;

    if(i>10)
    {
        kontrolerObj.symulacjaObj.stopSymulacji();
    }
}

//kontrolerObj.wczytajGre();




return 0;
}
