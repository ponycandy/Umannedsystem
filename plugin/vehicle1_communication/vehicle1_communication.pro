#QT       += core gui testlib network qmqtt
QT       += core gui testlib network qmqtt

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TEMPLATE = lib
DEFINES += VEHICLE1_COMMUNICATION_LIBRARY
DEFINES += QT_DEPRECATED_WARNINGS
DESTDIR = ../../build
INCLUDEPATH +=/opt/ros/melodic/include
DEPENDPATH +=/opt/ros/melodic/include


LIBS += -L/opt/ros/melodic/lib -lroscpp -lroslib -lrosconsole -lroscpp_serialization -lrostime

INCLUDEPATH += ../../build/config
INCLUDEPATH += ../../include
INCLUDEPATH += ../../

SOURCES += \
    mqttpublisher.cpp \
    pubthread.cpp \
    subthread.cpp \
    vehicle1_communicationActivator.cpp



HEADERS += \
    mqttpublisher.h \
    pubthread.h \
    subthread.h \
    vehicle1_communicationActivator.h


