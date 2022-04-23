QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Kontroler.cpp \
    Symulacja.cpp \
    Warunki.cpp \
    formazycia.cpp \
    main.cpp \
    mainwindow.cpp \
    settingswindow.cpp \
    zlozonaformazycia.cpp

HEADERS += \
    Kontroler.h \
    Symulacja.h \
    Warunki.h \
    formazycia.h \
    mainwindow.h \
    settingswindow.h \
    zlozonaformazycia.h

FORMS += \
    mainwindow.ui \
    settingswindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Pliki/tablica_init.csv
