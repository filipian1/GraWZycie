#include "Symulacja.h"
using namespace std;

Symulacja::Symulacja(int _x, int _y,int _stan_pocz, int _min_zycie,
                     int _max_zycie, int _min_smierc, int _max_smierc )
    :zycieWarunkiObj(_min_zycie,_max_zycie)
    ,smiercWarunkiObj(_min_smierc, _max_smierc) {

    //zerowy krok symulacji
    krokSymulacji_=0;
    //inicjalizacja komorek
//    cout<<"Symulacja konstruktor" << endl;

    wymiarXY_.push_back(_x);
    wymiarXY_.push_back(_y);
    vector<int> wiersz;

    //utworzenie tablicy komorek
    for(int i=0;i<wymiarXY_[1];i++)
    {
        //zerowanie wiersza
        wiersz.clear();
        for(int j=0;j<wymiarXY_[0];j++)
        {
          wiersz.push_back(_stan_pocz);
        }

      tablicaKomorek_.push_back(wiersz);
    }
    //status poczatkowy symulacji
    statusSymulacji_=false;
}

Symulacja::~Symulacja(){}

void Symulacja::startSymulacji(){
    statusSymulacji_=true;
}

void Symulacja::stopSymulacji(){
    statusSymulacji_=false;
}

void Symulacja::resetSymulacji(){
    statusSymulacji_=false;
}

void Symulacja::initTablicaKomorek(string _plik_init){

//    cout << "Inicjalizacja Tablicy Komorek"<<endl;
    string line, text, row, temp, word;
    fstream moj_plik;
    vector<int> wiersz;
//    cout << "FILEPATH: " << _plik_init << endl;

    //otworzenie pliku
    moj_plik.open(_plik_init, ios::in);
    if(moj_plik.is_open())
    {
        cout << "udalo sie otworzyc plik" <<endl;

        //zerowanie komórek
        tablicaKomorek_.clear();

        //odczyt pliku
        while (getline(moj_plik, line)) {
                wiersz.clear();         //zerowanie wiersza
                stringstream str(line); //uzycie stringstream to przeiterowania przez kolumny

                //odczyt kolumn i zapisanie to tablicyKomorek
                while(getline(str, word, '\t')){
                    wiersz.push_back(stoi(word));
                }
                tablicaKomorek_.push_back(wiersz);
        }

    }
    else
        cout << "Nie znaleziono pliku"<<endl;

    cout << "Komorki po wczytaniu:" <<endl;
    printTablica_komorek();
    moj_plik.close(); //zamkniecie pliku

    cout << "Zamknieto plik" << endl;
}

void  Symulacja::printTablica_komorek(){
    //wyswietlenie tablicy komorek
    int kolumny = wymiarXY_[0];
    int wiersze = wymiarXY_[1];

    cout <<"W print tablica" << endl;
    for(int w=0;w<wiersze;w++){
        for(int k=0;k<kolumny;k++){
            if (tablicaKomorek_[w][k] == 0)
                  cout <<". ";
            else
                  cout <<"* ";
        }
        cout << endl;
    }
}


void Symulacja::obliczNastepnyKrokSymulacji(){

    cout << "Krok symulacji nr: " << krokSymulacji_ << endl;
    int kolumny = wymiarXY_[0];
    int wiersze = wymiarXY_[1];
    vector<vector< int >> przyszle_komorki;
    przyszle_komorki=tablicaKomorek_;


    //wyswietlenie tablicy komorek

 printTablica_komorek();


    for(int w=1;w<wiersze-1;w++){
        for(int k=1;k<kolumny-1;k++){

            //zliczanie zywych sasiadow dla kazdej komorki
            int zywi_sasiedzi=0;
            for (int i = -1; i < 2; i++)
                for (int j = -1; j < 2; j++)
                    zywi_sasiedzi += tablicaKomorek_[w + i][k + j];

            //odjecie komorki centralnej
            zywi_sasiedzi -= tablicaKomorek_[w][k];

            //Sprawdzanie warunkow przezycia:

           vector< int > _smiercWarunki = smiercWarunkiObj.warunekIloscKomorek();
           vector< int > _zycieWarunki  = zycieWarunkiObj.warunekIloscKomorek();

//            cout << "rozmiar: "<<_smiercWarunki.size() << endl;

//            copy(_smiercWarunki.begin(), _smiercWarunki.end(), ostream_iterator<int>(cout," | "));

//            cout << "po problemie" <<endl;

          //  cout << "Warunki: " << _smiercWarunki[0] << " "<< _smiercWarunki[1]<< " " << _zycieWarunki[0]<< " " <<_zycieWarunki[1] << endl;


            //Warunki smierci komorki
            if ((tablicaKomorek_[w][k] == 1) && ((zywi_sasiedzi < _smiercWarunki[0])|| (zywi_sasiedzi > _smiercWarunki[1])))
                przyszle_komorki[w][k] = 0;

            //Narodziny komorki
            else if ((tablicaKomorek_[w][k] == 0) && ((zywi_sasiedzi >= _zycieWarunki[0]) && (zywi_sasiedzi <= _zycieWarunki[1])) )
                przyszle_komorki[w][k] = 1;

            //Brak zmian
            else
                przyszle_komorki[w][k] = tablicaKomorek_[w][k];
        }
    }
    //przepisanie wartosci z przyszlych komorek do  tablicyKomorek_:
//    tablicaKomorek_.clear();
    tablicaKomorek_=przyszle_komorki;

    //inkrementacja kroku symulacji
    krokSymulacji_++;

}

bool Symulacja::statusSymulacji() const
{
    return statusSymulacji_;
}

void Symulacja::setStatusSymulacji(bool newStatusSymulacji)
{
    statusSymulacji_ = newStatusSymulacji;
}

int Symulacja::krokSymulacji() const
{
    return krokSymulacji_;
}

const vector<vector<int> > &Symulacja::tablicaKomorek() const
{
    return tablicaKomorek_;
}

void Symulacja::setTablicaKomorek(const vector<vector<int> > &newTablicaKomorek)
{
    tablicaKomorek_ = newTablicaKomorek;
}


