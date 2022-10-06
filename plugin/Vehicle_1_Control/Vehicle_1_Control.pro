QT       += core gui testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TEMPLATE = lib
DEFINES += VEHICLE_1_CONTROL_LIBRARY
DEFINES += QT_DEPRECATED_WARNINGS
DESTDIR = ../../build
INCLUDEPATH +=/opt/ros/melodic/include
DEPENDPATH +=/opt/ros/melodic/include

LIBS += -L/opt/ros/melodic/lib -lroscpp -lroslib -lrosconsole -lroscpp_serialization -lrostime

INCLUDEPATH += ../../build/config
INCLUDEPATH += ../../include
INCLUDEPATH += ../../

SOURCES += \
    Vehicle_1_ControlActivator.cpp \
 \#    vehicle1_control_widget.cpp
    control_main_widget.cpp \
    inputwidget.cpp



HEADERS += \
    Vehicle_1_ControlActivator.h \
 \#    vehicle1_control_widget.h
    control_main_widget.h \
    inputwidget.h

#FORMS += vehicle1_control_widget.ui

FORMS += \
    inputwidget.ui


