#include "settingswindow.h"
#include "ui_settingswindow.h"
#include <vector>
#include "mainwindow.h"


SettingsWindow::SettingsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);
    vector<int> war;
    war.push_back(1);
    war.push_back(2);
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::on_bZamknijButton_clicked()
{
    SettingsWindow::accept();
}


int SettingsWindow::maxSmierc() const
{
    return maxSmierc_;
}

void SettingsWindow::setMaxSmierc(int newMaxSmierc){
    maxSmierc_ = newMaxSmierc;

    ui->sBoxPrzezycieMax->setValue(maxSmierc_);
}

int SettingsWindow::minSmierc() const{
    return minSmierc_;
}

void SettingsWindow::setMinSmierc(int newMinSmierc){
    minSmierc_ = newMinSmierc;
    ui->sBoxPrzezycieMin->setValue(minSmierc_);
}

int SettingsWindow::maxZycie() const{
    return maxZycie_;
}

void SettingsWindow::setMaxZycie(int newMaxZycie){
    maxZycie_ = newMaxZycie;
    ui->sBoxZycieMax->setValue(maxZycie_);
}

int SettingsWindow::minZycie() const{
    return minZycie_;
}

void SettingsWindow::setMinZycie(int newMinZycie){
    minZycie_ = newMinZycie;
    ui->sBoxZycieMin->setValue(minZycie_) ;
}


void SettingsWindow::on_sBoxZycieMin_valueChanged(int arg1)
{
    setMinZycie(arg1);
}

void SettingsWindow::on_sBoxZycieMax_valueChanged(int arg1)
{
    setMaxZycie(arg1);
}



void SettingsWindow::on_sBoxPrzezycieMin_valueChanged(int arg1)
{
    setMinSmierc(arg1);

}


void SettingsWindow::on_sBoxPrzezycieMax_valueChanged(int arg1)
{
    setMaxSmierc(arg1);
}



