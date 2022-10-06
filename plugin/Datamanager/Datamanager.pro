QT       += core gui testlib xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TEMPLATE = lib
DEFINES += DATAMANAGER_LIBRARY
DEFINES += QT_DEPRECATED_WARNINGS
INCLUDEPATH +=/opt/ros/melodic/include
DEPENDPATH +=/opt/ros/melodic/include
LIBS += -L/opt/ros/melodic/lib -lroscpp -lroslib -lrosconsole -lroscpp_serialization -lrostime
DESTDIR = ../../build
INCLUDEPATH += ../../build/config
INCLUDEPATH += ../../include
INCLUDEPATH += ../../

SOURCES += \
    DatamanagerActivator.cpp \
    datacollection.cpp \
    messagecollector.cpp \
    netconfigwidget.cpp



HEADERS += \
    DatamanagerActivator.h \
    datacollection.h \
    messagecollector.h \
    netconfigwidget.h

FORMS += \
    netconfigwidget.ui


