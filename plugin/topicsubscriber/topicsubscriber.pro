QT       += core gui testlib xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TEMPLATE = lib
DEFINES += TOPICSUBSCRIBER_LIBRARY
DEFINES += QT_DEPRECATED_WARNINGS
DESTDIR = ../../build

INCLUDEPATH +=/opt/ros/melodic/include
DEPENDPATH +=/opt/ros/melodic/include
LIBS += -L/opt/ros/melodic/lib -lroscpp -lroslib -lrosconsole -lroscpp_serialization -lrostime -lrviz
LIBS += -lboost_system -ljsoncpp -lboost_thread -lboost_filesystem -lboost_regex -lconsole_bridge
INCLUDEPATH += ../../build/config
INCLUDEPATH += ../../include
INCLUDEPATH += ../../
INCLUDEPATH += /usr/include/OGRE

SOURCES += \
    listen_thread.cpp \
    nodemanager.cpp \
    pub_thread.cpp \
    ros_rviz_widget.cpp \
    topicsubscriberActivator.cpp \
    rosnodemanager.cpp \
    singleshot.cpp



HEADERS += \
    listen_thread.h \
    nodemanager.h \
    pub_thread.h \
    ros_rviz_widget.h \
    topicsubscriberActivator.h\
    rosnodemanager.h \
    singleshot.h

FORMS += \
    ros_rviz_widget.ui \
    rosnodemanager.ui


