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
    MainWindow(int,int, int , int , int, int, int, QWidget*);
    ~MainWindow();
    Kontroler kontrolerObj;
    void kolorowanieTablicaKomorek();
    void ustawieniaTablicyKomorek();
    void wczytajDanePoczatkowe(string);
    void komunikatPoczatkowy();

public slots:
    void slotNastepnyKrok();
    void slotZmienOkres();

private slots:
    void on_bStartButton_clicked();
    void on_bPauzaButton_clicked();
    void on_bResetButton_clicked();
    void on_bLoadButton_clicked();
    void on_bSettingsButton_clicked();
    void on_bCloseButton_clicked();
    void on_tWTablicaKomorek_cellActivated(int row, int column);
    void on_tWTablicaKomorek_cellClicked(int row, int column);
    void on_bSaveButton_clicked();
    void on_bRandomButton_clicked();
    void on_pButtonDodajFormeZycia_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timerAktualizacji_;
};
#endif // MAINWINDOW_H
