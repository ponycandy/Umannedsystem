#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include <QObject>
#include  <QtXml>
#include <QDomDocument>
#include <QString>
#include <QMap>
#include "plugininterface.h"
#include "plugincontext.h"

class pluginmanager : public QObject
{
    Q_OBJECT
public:
    explicit pluginmanager();
    void readconfigfile(const char* filepath);
    bool loadplugin();
    void startplugin();
    void initplugin();
    void setupevent();
    void ReadXMLFile(const QString sFileName);
    void ShowXMLDoc(QDomElement &docElem);
    void InitCONTEXT();
    int m_pluginnum;
    QMap<int, QString> m_pluginnamemap;
    QMap<int, PluginInterface*> m_pluginmap;

    PluginContext* P_CONTEXT;

signals:

};

#endif // PLUGINMANAGER_H
