QT       += core gui testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TEMPLATE = lib
DEFINES += OCU_CAR_MANAGER_LIBRARY
DEFINES += QT_DEPRECATED_WARNINGS
DESTDIR = ../../build

INCLUDEPATH += ../../build/config
INCLUDEPATH += ../../include
INCLUDEPATH += ../../

SOURCES += \
    ocu_car_managerActivator.cpp \
    startwindow.cpp \
    viewmanager.cpp \
    whitewidget.cpp



HEADERS += \
    ocu_car_managerActivator.h \
    startwindow.h \
    viewmanager.h \
    whitewidget.h

FORMS += \
    startwindow.ui \
    whitewidget.ui

RESOURCES += iconresource.qrc
