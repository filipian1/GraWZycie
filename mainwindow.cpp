#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Kontroler.h"
#include "settingswindow.h"
#include "formazycia.h"
#include "zlozonaformazycia.h"


MainWindow::MainWindow( int _okres,int _x, int _y, int _min_zycie, int _max_zycie, int _min_smierc, int _max_smierc, QWidget *parent=0)
    : QMainWindow(parent)
   , kontrolerObj(_okres, _x,  _y,  _min_zycie, _max_zycie,  _min_smierc, _max_smierc)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timerAktualizacji_ = new QTimer(this);
    connect(timerAktualizacji_, SIGNAL(timeout()),this, SLOT(slotNastepnyKrok()));
    //poczatkowy okres symulacji
    int okres_pocz=kontrolerObj.symulacjaObj_.okresAktualizacji();;
    ui->hSliderOkres->setValue(okres_pocz);
    ui->lcdOkres->display(okres_pocz);
    connect(ui->hSliderOkres,SIGNAL(valueChanged(int)),
           this, SLOT(slotZmienOkres()));


    kontrolerObj.wczytajFormeZycia("Boxik","..\\GraWZycie\\Pliki\\FormyZycia\\Blok.csv");

   // komunikatPoczatkowy();

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::kolorowanieTablicaKomorek()
{

    qDebug()<<"kolorowanie TAblicy komorek3";

    int rozmiar_x=ui->tWTablicaKomorek->columnCount();
    int rozmiar_y=ui->tWTablicaKomorek->rowCount();

    for (int i =0;i<rozmiar_x;i++){

        //czysczenei tablicy

        for (int j =0;j<rozmiar_y;j++){
            QTableWidgetItem *tabItem = new QTableWidgetItem();
            ui->tWTablicaKomorek->setItem(j,i,tabItem);
            ui->tWTablicaKomorek->item(j,i)->setBackground(Qt::white);

            if(kontrolerObj.symulacjaObj_.tablicaKomorek_[j][i]==1){
//                qDebug() << "1";
         //       ui->tWTablicaKomorek->currentItem()->setBackground(Qt::green);
                ui->tWTablicaKomorek->item(j,i)->setBackground(Qt::green);
//                qDebug() << "2";
            }
            else{
                ui->tWTablicaKomorek->item(j,i)->setBackground(Qt::white);

            }
        }
    }
}

//funkcja odwolujaca sie do obliczania nastepnego kroku, a takze do
void MainWindow::slotNastepnyKrok()
{
    if (kontrolerObj.symulacjaObj_.statusSymulacji()==true){
        kontrolerObj.symulacjaObj_.obliczNastepnyKrokSymulacji();
        kolorowanieTablicaKomorek();
        ui->lcdKrok->display(kontrolerObj.symulacjaObj_.krokSymulacji());
    }
}

void MainWindow::slotZmienOkres()
{
    timerAktualizacji_->stop();

    int _nowyOkres=ui->hSliderOkres->value();
    ui->lcdOkres->display(_nowyOkres);
    kontrolerObj.symulacjaObj_.setOkresAktualizacji(_nowyOkres);
    timerAktualizacji_->start(_nowyOkres);
}

//Kontroler MainWindow::InitKontroler()


void MainWindow::on_bStartButton_clicked()
{
//   qDebug() << "Ktos klinkal przycisk";

    kontrolerObj.startGry();
    int okres =  kontrolerObj.symulacjaObj_.okresAktualizacji();
    qDebug() << "Okres poczatkowy wynosi: " << okres << "[ms]";
    timerAktualizacji_->start(okres);
}

void MainWindow::on_bPauzaButton_clicked()
{
    timerAktualizacji_->stop();
    kontrolerObj.pauzaGry();
}

void MainWindow::on_bResetButton_clicked()
{
    timerAktualizacji_->stop();
    kontrolerObj.resetGry();
    kolorowanieTablicaKomorek();
    ui->lcdKrok->display(kontrolerObj.symulacjaObj_.krokSymulacji());
    QMessageBox::information(this,"Informacja", "Zastopowano symulacje", QMessageBox::Ok);
}


void MainWindow::on_bSaveButton_clicked()
{
    qDebug() <<" Save button clicked";

    if(kontrolerObj.symulacjaObj_.statusSymulacji()==false){
        QFileDialog dialogSave(this);
        dialogSave.setFileMode(QFileDialog::AnyFile);

        auto fileName = dialogSave.getSaveFileName(this,
         tr("Zapisz grę"), "ZapisaneGry\\", tr("Zapisane gry (*.csv)"));

         qDebug() <<"filename to:" << fileName;

         kontrolerObj.zapiszGre(fileName.toStdString());

//         string file_name="C:\\gieramoja.csv";
//         kontrolerObj.zapiszGre(file_name);
//         kontrolerObj.writeXD();
         qDebug() << "czy udalo sie zapisac gre?";

    }
    else{
             QMessageBox::warning(this,"Uwaga","Nie można wczytać gry gdy trwa symulacja, wciśnij PAUZĘ, aby zapisać grę");
    }


}

void MainWindow::on_bLoadButton_clicked()
{
   qDebug() <<" Load button clicked";

   if(kontrolerObj.symulacjaObj_.statusSymulacji()==false){
       QFileDialog dialog(this);
       dialog.setFileMode(QFileDialog::AnyFile);
       auto fileName = dialog.getOpenFileName(this,
        tr("Wczytaj grę"), "ZapisaneGry\\", tr("Zapisane gry (*.csv)"));
        qDebug() <<"filename to:" << fileName;

        wczytajDanePoczatkowe(fileName.toStdString());

        ustawieniaTablicyKomorek();


   }
   else{
            QMessageBox::warning(this,"Uwaga","Nie można wczytać gry gdy trwa symulacja");
   }
}

void MainWindow::on_bSettingsButton_clicked()
{
    SettingsWindow settingsWindowObj;
    settingsWindowObj.setModal(true);


    vector< int > smiercWarunki = kontrolerObj.symulacjaObj_.smiercWarunkiObj_.warunekIloscKomorek();
    vector< int > zycieWarunki  = kontrolerObj.symulacjaObj_.zycieWarunkiObj_.warunekIloscKomorek();

    settingsWindowObj.setMinSmierc(smiercWarunki[0]);
    settingsWindowObj.setMaxSmierc(smiercWarunki[1]);
    settingsWindowObj.setMinZycie(zycieWarunki[0]);
    settingsWindowObj.setMaxZycie(zycieWarunki[1]);

    settingsWindowObj.exec();

    qDebug()<< "Czy Wyszedlem z okna?";

    qDebug()<< settingsWindowObj.minSmierc();
    qDebug()<< settingsWindowObj.maxSmierc();
    qDebug()<< settingsWindowObj.minZycie();
    qDebug()<< settingsWindowObj.maxZycie();

    vector< int > noweSmiercWarunki;
    vector< int > noweZycieWarunki;

    noweSmiercWarunki.push_back(settingsWindowObj.minSmierc());
    noweSmiercWarunki.push_back(settingsWindowObj.maxSmierc());
    noweZycieWarunki.push_back(settingsWindowObj.minZycie());
    noweZycieWarunki.push_back(settingsWindowObj.maxZycie());

    kontrolerObj.symulacjaObj_.smiercWarunkiObj_.setWarunekIloscKomorek(noweSmiercWarunki);
    kontrolerObj.symulacjaObj_.zycieWarunkiObj_.setWarunekIloscKomorek(noweZycieWarunki);


    settingsWindowObj.close();
}

void MainWindow::on_bCloseButton_clicked()
{
    QMessageBox::StandardButton decyzja = QMessageBox::question(this,"Czy zamknac",
                                            "Czy jestes pewien, ze chcesz zamknac aplikacje", QMessageBox::Yes |QMessageBox::No);

    if (decyzja == QMessageBox::Yes){
        QApplication::quit();
    } else{
           qDebug() << "Kliknięto 'No";
    }

}

void MainWindow::ustawieniaTablicyKomorek()
{
    qDebug() << "UStawianie szerokosci1";
//    int rozmiar_x=ui->tWTablicaKomorek->columnCount();
//    int rozmiar_y=ui->tWTablicaKomorek->rowCount();
    int rozmiar_x=kontrolerObj.symulacjaObj_.wymiarXY_[0];
    int rozmiar_y= kontrolerObj.symulacjaObj_.wymiarXY_[1];

    qDebug() << rozmiar_x << rozmiar_y;

    ui->tWTablicaKomorek->setRowCount(rozmiar_y);
    ui->tWTablicaKomorek->setColumnCount(rozmiar_x);

         qDebug() << "Wielkosci tablicy:" << ui->tWTablicaKomorek->rowCount() <<ui->tWTablicaKomorek->colorCount();

    int komSzerokosc=ui->tWTablicaKomorek->width()/rozmiar_x;
    int komWysokosc=ui->tWTablicaKomorek->height()/rozmiar_y;

   qDebug() << "Wielkosci komorek" << komSzerokosc << komWysokosc;

    for (int i =0;i<rozmiar_x;i++)
    {
        ui->tWTablicaKomorek->setColumnWidth(i, komSzerokosc);

      //  qDebug() << "Szerokosc Komorki" << ui->tWTablicaKomorek->columnWidth(i);

    }

    for (int i =0;i<rozmiar_y;i++)
    {
        ui->tWTablicaKomorek->setRowHeight(i, komWysokosc);
       //qDebug() << "Wysokosc Komorki" << ui->tWTablicaKomorek->rowHeight(i);

    }

//    ui->tWTablicaKomorek->horizontalHeader()->setStretchLastSection(true);
//    ui->tWTablicaKomorek->verticalHeader()->setStretchLastSection(true);
 //   qDebug() << "UStawianie szerokosci2";

}

void MainWindow::wczytajDanePoczatkowe(string plik_init)
{
  kontrolerObj.wczytajGre(plik_init);

  kolorowanieTablicaKomorek();
  qDebug() << "wczytano dane poczatkowe --------------------------------";

}

void MainWindow::komunikatPoczatkowy()
{
    QMessageBox::information(this,"Informacja w wiadomosci",
                             "Zaznacz komorki, ktore mają być zywe w pierwszym kroku symulacji a nastepnie klknij start", QMessageBox::Ok);
}


void MainWindow::on_tWTablicaKomorek_cellActivated(int row, int column)
{

}


void MainWindow::on_tWTablicaKomorek_cellClicked(int row, int column)
{
    qDebug() << "Kliknięto w  komórkę: " << row << column;
    QTableWidgetItem *myItem = new QTableWidgetItem();
    ui->tWTablicaKomorek->setItem(row,column, myItem);
    ui->tWTablicaKomorek->currentItem()->setBackground(Qt::green);
    kontrolerObj.symulacjaObj_.tablicaKomorek_[row][column]=1;
}



void MainWindow::on_bRandomButton_clicked()
{
    kontrolerObj.symulacjaObj_.resetSymulacji();
    kontrolerObj.symulacjaObj_.losowyStanPoczatkowy();
    kolorowanieTablicaKomorek();

}


void MainWindow::on_pButtonDodajFormeZycia_clicked()
{

    QString typFormy = ui->cBoxFormaZycia->currentText();
    string typFormyStd= typFormy.toStdString();
    QString sciezka = "..\\GraWZycie\\Pliki\\FormyZycia\\"+typFormy+".csv";
    string sciezkaStd=sciezka.toStdString();

    int x = ui->tWTablicaKomorek->currentColumn();
    int y = ui->tWTablicaKomorek->currentRow();

    qDebug() << "kliknieto w przycisk" << typFormy<<sciezka <<x << y;
    if(typFormy=="Blinker"){
        qDebug() << "Blinker";
        FormaZycia prostaFormaZyciaObj;
        prostaFormaZyciaObj = kontrolerObj.wczytajFormeZycia(typFormyStd,sciezkaStd);

        prostaFormaZyciaObj.setPozycjaXY(x,y);
        qDebug() << "znowu w mainwindow wymiar: " <<prostaFormaZyciaObj.rozmiarXY();


        kontrolerObj.rysujFormeZycia(prostaFormaZyciaObj);

        kolorowanieTablicaKomorek();

    }else{
        ZlozonaFormaZycia zlozonaFormaZyciaObj;
        zlozonaFormaZyciaObj = kontrolerObj.wczytajZlozonaFormeZycia(typFormyStd,sciezkaStd);

        zlozonaFormaZyciaObj.setPozycjaXY(x,y);
        qDebug() << "znowu w mainwindow wymiar: " <<zlozonaFormaZyciaObj.rozmiarXY()[0] <<zlozonaFormaZyciaObj.rozmiarXY()[1];
        kontrolerObj.rysujZlozonaFormeZycia(zlozonaFormaZyciaObj);
        kolorowanieTablicaKomorek();

    }




}

