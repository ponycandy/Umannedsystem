#include <QApplication>
#include <configfile.h>
#include "pluginmanager.h"

#if defined (Q_OS_WIN32)
#else
#include "ros/ros.h"
#endif
int main(int argc, char *argv[])
{
#if defined (Q_OS_WIN32)
#else
       ros::init(argc,argv,"UCS_node",ros::init_options::AnonymousName);
#endif
    QApplication a(argc, argv);
    pluginmanager* m_manager=new pluginmanager;
    m_manager->InitCONTEXT();
    m_manager->readconfigfile(FILEPATH::pluginfile);
    m_manager->loadplugin();
    m_manager->initplugin();
    m_manager->startplugin();
   // qDebug()<<"plugin already start";
    //m_manager->setupevent();
    return a.exec();
}
