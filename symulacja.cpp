#include "Symulacja.h"

using namespace std;

Symulacja::Symulacja(int okres, int x, int y, int min_zycie,
                     int max_zycie, int min_smierc, int max_smierc )
    :zycieWarunkiObj_(min_zycie,max_zycie)
    ,smiercWarunkiObj_(min_smierc, max_smierc) {

    //inicjalizacja okresu aktualizacji
    okresAktualizacji_=okres;
    statusSymulacji_=false;
    setKrokSymulacji(1);


    wymiarXY_.push_back(x);
    wymiarXY_.push_back(y);
    //poczatkowy reset symulacji
    initTablicaKomorek();

}

Symulacja::~Symulacja(){}

void Symulacja::startSymulacji(){
    statusSymulacji_=true;
//ustawienie pierwszego kroku jako 1

}
void Symulacja::stopSymulacji(){
   statusSymulacji_=false;
}

void Symulacja::resetSymulacji(){
    //status poczatkowy symulacji

    statusSymulacji_=false;
    setKrokSymulacji(1);

    for(int i=0;i<wymiarXY_[1];i++){
        //zerowanie wiersza
        for(int j=0;j<wymiarXY_[0];j++){
            tablicaKomorek_[i][j]=0;
        }
    }


}
void Symulacja::loadTablicaKomorek(string file_path){

    statusSymulacji_=false;
    setKrokSymulacji(1);

//    cout << "Inicjalizacja Tablicy Komorek"<<endl;
    string line, text, row, temp, word;
    fstream mojPlik;
    vector<int> wiersz;
//    cout << "FILEPATH: " << file_path << endl;

    //otworzenie pliku
    mojPlik.open(file_path, ios::in);
    if(mojPlik.is_open())
    {
        cout << "udalo sie otworzyc plik" <<endl;
        //zerowanie komórek
        tablicaKomorek_.clear();
       //odczyt pliku
        while (getline(mojPlik, line)) {
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
    cout << "Wymiary tablicy po wczytaniu" << tablicaKomorek_.size() << "\t"<< tablicaKomorek_[0].size();

    wymiarXY_[0]=tablicaKomorek_[0].size();
    wymiarXY_[1]=tablicaKomorek_.size();
    printTablicaKomorek();
    mojPlik.close(); //zamkniecie pliku

    cout << "Zamknieto plik" << endl;
}

void Symulacja::saveTablicaKomorek(string file_path)
{
    ofstream mojPlik;
    //otworzenie pliku
    mojPlik.open(file_path);
    if(mojPlik.is_open()==true)
    {
        cout << "udalo sie utworzyc nowy plik" <<endl;

        int kolumny = wymiarXY_[0];
        int wiersze = wymiarXY_[1];
        //zapisanie danych
        for(int w=0;w<wiersze;w++){
            for(int k=0;k<kolumny;k++){
                if (tablicaKomorek_[w][k] == 0)
                      mojPlik <<"0 \t";
                else
                      mojPlik <<"1 \t";
            }
            mojPlik << endl;
        }
    }
    else{
        cout <<"nie udalo sie utworzyc pliku";
    }
    mojPlik.close();


}

void Symulacja::initTablicaKomorek()
{
    vector<int> wiersz;
    //utworzenie tablicy komorek
    for(int i=0;i<wymiarXY_[1];i++){
        //zerowanie wiersza
        wiersz.clear();
        for(int j=0;j<wymiarXY_[0];j++){
          wiersz.push_back(stanPoczatkowy_);
        }

      tablicaKomorek_.push_back(wiersz);
    }
}

void Symulacja::losowyStanPoczatkowy()
{
    statusSymulacji_=false;
    setKrokSymulacji(1);

    for(int i=0;i<wymiarXY_[1];i++){
        for(int j=0;j<wymiarXY_[0];j++){
            //randomowa wartosc z zbioru {0,1}
            tablicaKomorek_[i][j]=rand() %2;
        }
    }
}

void  Symulacja::printTablicaKomorek(){
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

 if (statusSymulacji_==true){
    cout << "Krok symulacji nr: " << krokSymulacji_ << endl;
    int kolumny = wymiarXY_[0];
    int wiersze = wymiarXY_[1];
    vector<vector< int >> przyszle_komorki;
    przyszle_komorki=tablicaKomorek_;

  //wyswietlenie tablicy komorek

 printTablicaKomorek();

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

           vector< int > _smiercWarunki = smiercWarunkiObj_.warunekIloscKomorek();
           vector< int > _zycieWarunki  = zycieWarunkiObj_.warunekIloscKomorek();

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
    tablicaKomorek_=przyszle_komorki;

    //inkrementacja kroku symulacji
    krokSymulacji_++;

 }

}

bool Symulacja::statusSymulacji() const{
    return statusSymulacji_;
}

void Symulacja::setStatusSymulacji(bool newStatusSymulacji){
    statusSymulacji_ = newStatusSymulacji;
}

int Symulacja::krokSymulacji() const
{
    return krokSymulacji_;
}

void Symulacja::setKrokSymulacji(int nowy_krok)
{
    krokSymulacji_=nowy_krok;
}

//const vector<vector<int> > &Symulacja::tablicaKomorek() const
//{
//    return tablicaKomorek_;
//}

//void Symulacja::setTablicaKomorek(const vector<vector<int> > &newTablicaKomorek)
//{
//    tablicaKomorek_ = newTablicaKomorek;
//}

void Symulacja::setOkresAktualizacji(int _nowy_okres){
    okresAktualizacji_=_nowy_okres;
}

int Symulacja::okresAktualizacji(){
    return okresAktualizacji_;
}

