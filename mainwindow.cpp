#include <QDebug>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Kontroler.h"
#include "settingswindow.h"


MainWindow::MainWindow( int _okres,int _x, int _y,int _stan_pocz, int _min_zycie, int _max_zycie, int _min_smierc, int _max_smierc, QWidget *parent=0)
    : QMainWindow(parent)
   , kontrolerObj(_okres, _x,  _y, _stan_pocz,  _min_zycie, _max_zycie,  _min_smierc, _max_smierc)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timerAktualizacji = new QTimer(this);
    connect(timerAktualizacji, SIGNAL(timeout()),this, SLOT(slotNastepnyKrok()));

    connect(ui->hSliderOkres,SIGNAL(valueChanged(int)),
           this, SLOT(slotZmienOkres()));

    on_bLoadButton_clicked();


}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::kolorowanieTablicaKomorek()
{
    int rozmiar_x=ui->tWTablicaKomorek->columnCount();
    int rozmiar_y=ui->tWTablicaKomorek->rowCount();

    for (int i =0;i<rozmiar_x;i++){
        qDebug()<<"kolorowanie TAblicy komorek3";

        //czysczenei tablicy

        for (int j =0;j<rozmiar_y;j++){
            QTableWidgetItem *tabItem = new QTableWidgetItem();
            ui->tWTablicaKomorek->setItem(j,i,tabItem);
            ui->tWTablicaKomorek->item(j,i)->setBackground(Qt::white);

            if(kontrolerObj.symulacjaObj.tablicaKomorek_[j][i]==1){
                qDebug() << "1";
         //       ui->tWTablicaKomorek->currentItem()->setBackground(Qt::green);
                ui->tWTablicaKomorek->item(j,i)->setBackground(Qt::green);
//                qDebug() << "2";
            }
        }
    }
}

//funkcja odwolujaca sie do obliczania nastepnego kroku, a takze do
void MainWindow::slotNastepnyKrok()
{
    if (kontrolerObj.symulacjaObj.statusSymulacji()){
        kontrolerObj.symulacjaObj.obliczNastepnyKrokSymulacji();
        kolorowanieTablicaKomorek();
    }
}

void MainWindow::slotZmienOkres()
{
    timerAktualizacji->stop();

    int _nowyOkres=ui->hSliderOkres->value();
    ui->lcdOkres->display(_nowyOkres);
    kontrolerObj.symulacjaObj.setOkresAktualizacji(_nowyOkres);
    timerAktualizacji->start(_nowyOkres);
}

//Kontroler MainWindow::InitKontroler()


void MainWindow::on_bStartButton_clicked()
{
//   qDebug() << "Ktos klinkal przycisk";
   QMessageBox::information(this,"Informacja w wiadomosci", "Wystartowano symulacje", QMessageBox::Ok);

    kontrolerObj.startGry();
    int okres =  kontrolerObj.symulacjaObj.okresAktualizacji()*1000;
    qDebug() << "Okres poczatkowy wynosi: " << okres << "[ms]";
    timerAktualizacji->start(okres);
}


void MainWindow::on_bLoadButton_clicked()
{
   //TODO: Okno wczytywania gry
 string _plik_init="D:\\Users\\285732\\Documents\\WORKSPACES\\Qt\\GraWZycie\\Pliki\\tablica_init.csv";
 kontrolerObj.wczytajGre(_plik_init);
 kolorowanieTablicaKomorek();


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


void MainWindow::on_bSettingsButton_clicked()
{
    SettingsWindow settingsWindowObj;
    settingsWindowObj.setModal(true);
    settingsWindowObj.exec();
}


void MainWindow::on_bStopButton_clicked()
{
    QMessageBox::information(this,"Informacja", "Zastopowano symulacje", QMessageBox::Ok);
    timerAktualizacji->stop();
    kontrolerObj.stopGry();

}


void MainWindow::ustawieniaTablicyKomorek()
{
    int rozmiar_x=ui->tWTablicaKomorek->columnCount();
    int rozmiar_y=ui->tWTablicaKomorek->rowCount();
    int x=ui->tWTablicaKomorek->width();
    int y=ui->tWTablicaKomorek->height();
    for (int i =0;i<rozmiar_x;i++)
    {
        ui->tWTablicaKomorek->setColumnWidth(i, x/rozmiar_x);
    }

    for (int i =0;i<rozmiar_y;i++)
    {
        ui->tWTablicaKomorek->setRowHeight(i,y/rozmiar_y);
    }

    ui->tWTablicaKomorek->horizontalHeader()->setStretchLastSection(true);
    ui->tWTablicaKomorek->verticalHeader()->setStretchLastSection(true);
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
}

