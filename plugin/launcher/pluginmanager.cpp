#include "pluginmanager.h"
#include <QFile>
pluginmanager::pluginmanager()
{

}

void pluginmanager::readconfigfile(const char* filepath)
{
        QString sFileName = filepath;

        QDir mydir(filepath);
     //   qDebug()<<mydir.absoluteFilePath("plugin.xml");


          QFile fileName(mydir.absoluteFilePath("plugin.xml"));
        //QFile fileName("./test.txt");
     //   fileName.setFileName(sFileName);

        if(!fileName.exists())
        {
            return;
        }

        ReadXMLFile(sFileName);
}
bool pluginmanager::loadplugin()
{
        int i=1;
        QDir pluginsDir("");
      //  qDebug()<<pluginsDir.absoluteFilePath("plugin.xml");

        for(auto each : m_pluginnamemap.toStdMap())
        {
#if defined (Q_OS_WIN32)
            QString filename=each.second+".dll";
#else
            QString filename=each.second+".so";

#endif
            QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(filename));
            QObject *plugin = pluginLoader.instance();
            if (pluginLoader.isLoaded())
             {
                qDebug()<<filename<<"has been loaded";
            }
                else {
                qDebug()<<"fail to laod"<<filename;
            }

          //  qDebug()<<__FUNCTION__<<pluginLoader.errorString();
            if(plugin)
            {
               m_pluginmap.insert(i++, qobject_cast<PluginInterface*>(plugin));
            }
        }

        return true;
}
void pluginmanager::initplugin()
{
    for(auto each : m_pluginmap.toStdMap())
    {
        each.second->init(P_CONTEXT);
    }
}
void pluginmanager::startplugin()
{
    for(auto each : m_pluginmap.toStdMap())
    {
        each.second->start();
    }
}
void pluginmanager::setupevent()
{
    P_CONTEXT->setupevent();

}
void pluginmanager::ReadXMLFile(const QString sFileName)
{
    QDir mydir(sFileName);
    qDebug()<<mydir.absoluteFilePath("plugin.xml");
    QFile file(mydir.absoluteFilePath("plugin.xml"));
    //file.setFileName(sFileName);
    if (!file.open(QIODevice::ReadOnly ))
    {
        return;
    }
    QDomDocument pluginxml;

    pluginxml.setContent(&file);
    file.close();

    QDomElement root = pluginxml.documentElement();
    QDomElement node = root.firstChild().toElement();
    int i=1;
    while(node.isNull() == false)
       {
//           qDebug() << node.tagName();
           while(node.tagName() == "plugin")
           {

                   QString plugin_name=node.attribute("name","name");
                   m_pluginnamemap.insert(i++, plugin_name);

                   node = node.nextSibling().toElement();
           }
           while(node.tagName() == "pluginnum")
           {
                    m_pluginnum=node.attribute("value","value").toInt();
           }
           node = node.nextSibling().toElement();
       }
}

void pluginmanager::InitCONTEXT()
{
         QDir pluginsDir("./sealed");
#if defined (Q_OS_WIN32)
        QString filename="contextresolver.dll";
#else
         QString filename="contextresolver.so";

#endif
         qDebug()<<pluginsDir.absoluteFilePath(filename);
        QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(filename));
        QObject *plugin = pluginLoader.instance();
        if (pluginLoader.isLoaded())
         {
            qDebug()<<"contextresolver has been loaded";
        }
            else {
            qDebug()<<"fail to laod contextresolver";
        }

     //   qDebug()<<__FUNCTION__<<pluginLoader.errorString();
        P_CONTEXT=qobject_cast<PluginContext*>(plugin);

}
