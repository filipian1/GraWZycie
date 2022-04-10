#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Kontroler.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(int,int, int ,int, int , int, int, int, QWidget*);

    Kontroler kontrolerObj;
    ~MainWindow();

private slots:
    void on_bStartButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
