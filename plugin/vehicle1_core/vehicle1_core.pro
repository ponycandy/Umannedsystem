QT       += core gui testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TEMPLATE = lib
DEFINES += VEHICLE1_CORE_LIBRARY
DEFINES += QT_DEPRECATED_WARNINGS
DESTDIR = ../../build
INCLUDEPATH +=/opt/ros/melodic/include
DEPENDPATH +=/opt/ros/melodic/include

LIBS += -L/opt/ros/melodic/lib -lroscpp -lroslib -lrosconsole -lroscpp_serialization -lrostime

INCLUDEPATH += ../../build/config
INCLUDEPATH += ../../include
INCLUDEPATH += ../../

SOURCES += \
    startwindow.cpp \
    vehicle1_coreActivator.cpp \
    whitewidget.cpp



HEADERS += \
    startwindow.h \
    vehicle1_coreActivator.h \
    whitewidget.h

FORMS += \
    startwindow.ui \
    whitewidget.ui


