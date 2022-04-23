#include "Kontroler.h"
#include "Symulacja.h"
#include <iostream>
#include <formazycia.h>
#include <zlozonaformazycia.h>

//konstruktor klasy kontroler
//inicjalizuje Symulacje
Kontroler::Kontroler(int _okres,int _x, int _y, int _min_zycie, int _max_zycie, int _min_smierc, int _max_smierc)
          : symulacjaObj_(_okres,_x,  _y,  _min_zycie, _max_zycie,  _min_smierc, _max_smierc)
{
   cout <<"utworzylem obiekt klasy Kontroler" <<endl;
}

Kontroler::~Kontroler(){
}

void Kontroler::zapiszGre(string file_path){

    if (symulacjaObj_.statusSymulacji()==false){
        symulacjaObj_.saveTablicaKomorek(file_path);
    }
    else{
        cout <<"Nadal trwa symulacja" <<endl;
    }
}

void Kontroler::wczytajGre(string file_path){

    //wczytanie gry gdy symulacja jest zastopowana
    if (symulacjaObj_.statusSymulacji()==false){
        symulacjaObj_.loadTablicaKomorek(file_path);
    }
}

void Kontroler::startGry(){
    //uruchomienie symulacji
    symulacjaObj_.startSymulacji();
    //trwa symulacja
}

void Kontroler::resetGry(){
    //stop symulacji
    symulacjaObj_.resetSymulacji();
}

void Kontroler::pauzaGry(){
    symulacjaObj_.stopSymulacji();
}

void Kontroler::losowyStanPoczatkowy()
{

    symulacjaObj_.losowyStanPoczatkowy();

}

void Kontroler::rysujFormeZycia(FormaZycia mojaFormaZycia){

    cout << "rysujFormeZycia" <<endl;
    int rozmiar = mojaFormaZycia.rozmiarXY();
    cout << "rozmiar: " << rozmiar <<endl;

    int *poz=mojaFormaZycia.pozycjaXY();
    cout << poz[0] << poz[1 ]<<endl;

    for(int i=0;i<rozmiar;i++){
        symulacjaObj_.tablicaKomorek_[poz[1]][poz[0]+i]=mojaFormaZycia.tabFormaZycia_[i];
    }

}

FormaZycia Kontroler::wczytajFormeZycia(string nazwa, string file_path)
{
    FormaZycia formaZyciaObj1(nazwa, file_path);

    string line, text, row, temp, word;
    fstream mojPlik;
    int licznik_wierszy=0;
    int licznik_kolumn=0;

    int wartosci[1000];
    //otworzenie pliku
    mojPlik.open(file_path, ios::in);

    if(mojPlik.is_open())
    {
        cout << "udalo sie otworzyc plik" <<endl;
       //odczyt pliku
        while (getline(mojPlik, line)) {
                licznik_wierszy++;
                stringstream str(line); //uzycie stringstream to przeiterowania przez kolumny

                //odczyt kolumn i zapisanie to tablicyKomorek
                while(getline(str, word, '\t')){
                    wartosci[licznik_kolumn]=stoi(word);
                    licznik_kolumn++;
                }
        }
        if (licznik_wierszy>0){
            licznik_kolumn=licznik_kolumn/licznik_wierszy;

            if(licznik_wierszy==1){
                cout << "Podano Poprawny typ formy zycia" <<endl;
                formaZyciaObj1.setRozmiarXY(licznik_kolumn);
                //wypelnienie formy danych
                for(int i=0;i<licznik_kolumn;i++){
                    formaZyciaObj1.tabFormaZycia_.push_back(wartosci[i]);
                }

            }
            else {
                cout << "Podano Błędny typ formy zycia" <<endl;
            }
        }

        cout << "Licznik wierszy i kol: " << licznik_wierszy<< " " <<licznik_kolumn <<endl;
    }

    mojPlik.close();


return formaZyciaObj1;
}

void Kontroler::rysujZlozonaFormeZycia(ZlozonaFormaZycia mojaFormaZycia){

    cout << "rysujZlozonaFormeZycia" <<endl;
    int* prozmiar = mojaFormaZycia.rozmiarXY();
    cout << "prozmiar x i y: " << prozmiar[0] <<"  " << prozmiar[1] <<endl;

    int* poz=mojaFormaZycia.pozycjaXY();
    cout << "pozycje" << poz[0] << " " << poz[1]<<endl;

    for(int i=0;i<prozmiar[1];i++){
        for(int j=0;j<prozmiar[0];j++)
        symulacjaObj_.tablicaKomorek_[poz[1]+i][poz[0]+j]=mojaFormaZycia.tabFormaZycia_[i][j];
    }

}

ZlozonaFormaZycia Kontroler::wczytajZlozonaFormeZycia(string nazwa, string file_path)
{
    ZlozonaFormaZycia formaZyciaObj1(nazwa, file_path);

    string line, text, row, temp, word;
    fstream mojPlik;
    int licznik_wierszy=0;
    int licznik_kolumn=0;

    vector<int> wiersz;

    int wartosci[1000];
    //otworzenie pliku
    mojPlik.open(file_path, ios::in);

    if(mojPlik.is_open())
    {
        cout << "udalo sie otworzyc plik" <<endl;
       //odczyt pliku
        while (getline(mojPlik, line)) {
                licznik_wierszy++;
                stringstream str(line); //uzycie stringstream to przeiterowania przez kolumny

                //odczyt kolumn i zapisanie to tablicyKomorek
                while(getline(str, word, '\t')){
                    wartosci[licznik_kolumn]=stoi(word);
                    licznik_kolumn++;
                }
        }
        if (licznik_wierszy>0){
            licznik_kolumn=licznik_kolumn/licznik_wierszy;

            if(licznik_wierszy>1){
                cout << "Podano Poprawny typ formy zycia" <<endl;
                formaZyciaObj1.setRozmiarXY(licznik_kolumn,licznik_wierszy);
                //wypelnienie formy danych

            for(int i=0;i<licznik_wierszy;i++){
                wiersz.clear();
                for(int j=0;j<licznik_kolumn;j++){
                    wiersz.push_back(wartosci[j+(i*licznik_kolumn)]);

                }
                    formaZyciaObj1.tabFormaZycia_.push_back(wiersz);


            }
            }
            else {
                cout << "Podano Błędny typ formy zycia" <<endl;
            }
        }

        cout << "Licznik wierszy i kol: " << licznik_wierszy<< " " <<licznik_kolumn <<endl;
    }

    mojPlik.close();


return formaZyciaObj1;
}


