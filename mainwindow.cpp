#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include "Kontroler.h"

MainWindow::MainWindow( int _okres,int _x, int _y,int _stan_pocz, int _min_zycie, int _max_zycie, int _min_smierc, int _max_smierc, QWidget *parent=0)
    : QMainWindow(parent)
   , kontrolerObj(_okres, _x,  _y, _stan_pocz,  _min_zycie, _max_zycie,  _min_smierc, _max_smierc)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}

//Kontroler MainWindow::InitKontroler()
//{}

void MainWindow::on_bStartButton_clicked()
{
//   qDebug() << "Ktos klinkal przycisk";
   QMessageBox::information(this,"Informacja w wiadomosci", "NAcisnieto przycisk ", QMessageBox::Ok);

}

