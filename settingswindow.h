#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H
#include <Warunki.h>
#include <QDialog>

namespace Ui {
class SettingsWindow;
}

class SettingsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsWindow(QWidget *parent = nullptr);
    ~SettingsWindow();  
    int minZycie() const;
    void setMinZycie(int newMinZycie);

    int maxZycie() const;
    void setMaxZycie(int newMaxZycie);

    int minSmierc() const;
    void setMinSmierc(int newMinSmierc);

    int maxSmierc() const;
    void setMaxSmierc(int newMaxSmierc);

private slots:
    void on_bZamknijButton_clicked();
    void on_sBoxZycieMin_valueChanged(int arg1);


    void on_sBoxPrzezycieMax_valueChanged(int arg1);

    void on_sBoxZycieMax_valueChanged(int arg1);

    void on_sBoxPrzezycieMin_valueChanged(int arg1);

private:
    Ui::SettingsWindow *ui;
    int minZycie_;
    int maxZycie_;
    int minSmierc_;
    int maxSmierc_;


};

#endif // SETTINGSWINDOW_H
