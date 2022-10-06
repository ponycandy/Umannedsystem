QT       += core gui testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TEMPLATE = lib
DEFINES += VEHICLE1_LIBRARY
DEFINES += QT_DEPRECATED_WARNINGS
DESTDIR = ../../build

INCLUDEPATH += ../../build/config
INCLUDEPATH += ../../include
INCLUDEPATH += ../../

SOURCES += \
    mqttmanager.cpp \
    mqttpublisher.cpp \
    paramsetting.cpp \
    pubthread.cpp \
    subthread.cpp \
    vehicle1Activator.cpp



HEADERS += \
    mqttmanager.h \
    mqttpublisher.h \
    paramsetting.h \
    pubthread.h \
    subthread.h \
    vehicle1Activator.h

FORMS += \
    paramsetting.ui


