#QT       += core gui testlib network qmqtt
QT       += core gui testlib network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TEMPLATE = lib
DEFINES += VEHICLE1_COMMUNICATION_LIBRARY
DEFINES += QT_DEPRECATED_WARNINGS
DESTDIR = ../../build
INCLUDEPATH +=/opt/ros/melodic/include
DEPENDPATH +=/opt/ros/melodic/include


LIBS += -L/opt/ros/melodic/lib -lroscpp -lroslib -lrosconsole -lroscpp_serialization -lrostime
LIBS += -L../../3rdlib/mqtt -lQt5Qmqtt

INCLUDEPATH += ../../3rdlib/mqtt/include
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


