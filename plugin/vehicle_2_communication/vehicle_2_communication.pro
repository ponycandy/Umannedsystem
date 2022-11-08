QT       += core gui testlib qmqtt

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TEMPLATE = lib
DEFINES += VEHICLE_2_COMMUNICATION_LIBRARY
DEFINES += QT_DEPRECATED_WARNINGS
DESTDIR = ../../build
INCLUDEPATH +=/opt/ros/melodic/include
DEPENDPATH +=/opt/ros/melodic/include

LIBS += -L/opt/ros/melodic/lib -lroscpp -lroslib -lrosconsole -lroscpp_serialization -lrostime

INCLUDEPATH += ../../build/config
INCLUDEPATH += ../../include
INCLUDEPATH += ../../

SOURCES += \
    vehicle_2_communicationActivator.cpp \
    mqttpublisher.cpp \
    pubthread.cpp \
    subthread.cpp \



HEADERS += \
    vehicle_2_communicationActivator.h \
    mqttpublisher.h \
    pubthread.h \
    subthread.h \


