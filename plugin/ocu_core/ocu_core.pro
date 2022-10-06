QT       += core gui testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TEMPLATE = lib
DEFINES += OCU_CORE_LIBRARY
DEFINES += QT_DEPRECATED_WARNINGS
DESTDIR = ../../build

INCLUDEPATH += ../../build/config
INCLUDEPATH += ../../include
INCLUDEPATH += ../../

SOURCES += \
    coremainwindow.cpp \
    coreviewmanager.cpp \
    ocu_coreActivator.cpp



HEADERS += \
    coremainwindow.h \
    coreviewmanager.h \
    ocu_coreActivator.h


