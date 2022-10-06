QT       += core gui testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TEMPLATE = lib
DEFINES += OCU_VIDEO_PLAYER_LIBRARY
DEFINES += QT_DEPRECATED_WARNINGS
DESTDIR = ../../build
INCLUDEPATH +=/opt/ros/melodic/include
DEPENDPATH +=/opt/ros/melodic/include

LIBS += -L/opt/ros/melodic/lib -lroscpp -lroslib -lrosconsole -lroscpp_serialization -lrostime

INCLUDEPATH += ../../build/config
INCLUDEPATH += ../../include
INCLUDEPATH += ../../

SOURCES += \
    ocu_video_playerActivator.cpp \
    video_display_manager.cpp



HEADERS += \
    ocu_video_playerActivator.h \
    video_display_manager.h

FORMS += \
    video_display_manager.ui


