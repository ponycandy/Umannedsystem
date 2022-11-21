#ifndef PLUGINCONTEXT_H
#define PLUGINCONTEXT_H

#include <QObject>
#include <QString>
#include "eventservice.h"
#include "xtlevent.h"
//定义接口
class PluginContext
{
public:

    virtual ~PluginContext(){}
    virtual void subscribeslot(QObject *reciever,const char *method,QString eventname,Qt::ConnectionType type) = 0;
    virtual void subscribeslot(QString name,EventService *handle)=0;
    virtual void registerservice(QObject *service,QString name) = 0;
    virtual QObject* getservice(QString name)=0;
    virtual void publishsignal(QObject *sender,const char *signal,QString eventname,Qt::ConnectionType type)=0;
    virtual void setupevent()=0;
    virtual void postevent(XTLevent event)=0;



};

//一定是唯一的标识符
#define PluginContext_iid "Examples.Plugin.PluginContext"

QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(PluginContext,PluginContext_iid )
QT_END_NAMESPACE

#endif // DECLAREINTERFACE_H

