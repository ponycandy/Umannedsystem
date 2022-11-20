#include <QApplication>
#include <configfile.h>
#include "pluginmanager.h"
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <algorithm>
#if defined (Q_OS_WIN32)
#else
#include "ros/ros.h"
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    pluginmanager* m_manager=new pluginmanager;
    m_manager->InitCONTEXT();
    m_manager->readconfigfile(FILEPATH::pluginfile);
    m_manager->loadplugin();
    m_manager->initplugin();
    m_manager->startplugin();
    return a.exec();
}
