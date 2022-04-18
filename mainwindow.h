#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "Kontroler.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(int,int, int ,int, int , int, int, int, QWidget*);
    ~MainWindow();
    Kontroler kontrolerObj;
    void kolorowanieTablicaKomorek();
    void ustawieniaTablicyKomorek();


public slots:
    void slotNastepnyKrok();
    void slotZmienOkres();


private slots:
    void on_bStartButton_clicked();

    void on_bLoadButton_clicked();

    void on_bCloseButton_clicked();

    void on_bSettingsButton_clicked();

    void on_bStopButton_clicked();


    void on_tWTablicaKomorek_cellActivated(int row, int column);

    void on_tWTablicaKomorek_cellClicked(int row, int column);

private:
    Ui::MainWindow *ui;
    QTimer *timerAktualizacji;
};
#endif // MAINWINDOW_H
