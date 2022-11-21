#include <QApplication>
#include <configfile.h>
#include "pluginmanager.h"

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
