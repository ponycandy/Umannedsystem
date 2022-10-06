QT       += core gui testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TEMPLATE = lib
DEFINES += VEHICLE_1_VIDEO_LIBRARY
DEFINES += QT_DEPRECATED_WARNINGS
DESTDIR = ../../build
INCLUDEPATH +=/opt/ros/melodic/include
DEPENDPATH +=/opt/ros/melodic/include

LIBS += -L/opt/ros/melodic/lib -lroscpp -lroslib -lrosconsole -lroscpp_serialization -lrostime
include($$PWD/../../build/ffmpeg/ffmpeg.pri)
INCLUDEPATH += ../../build/config
INCLUDEPATH += ../../include
INCLUDEPATH += ../../

SOURCES += \
    vehicle_1_videoActivator.cpp \
    ./avplayer/avdecoder.cpp   \
    ./avplayer/avplayer.cpp \
    video_manager.cpp



HEADERS += \
    vehicle_1_videoActivator.h \
    ./avplayer/avdecoder.h   \
    ./avplayer/avplayer.h \
    video_manager.h


