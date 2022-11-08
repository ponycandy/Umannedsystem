#ifndef VEHICLE1_COMMUNICATION_H
#define VEHICLE1_COMMUNICATION_H
#ifndef QTPLUGIN_H
#define QTPLUGIN_H

#include <QObject>
#include <QtPlugin>
#include "plugininterface.h"
#include "service/eventservice.h"
#include "mqttpublisher.h"


class vehicle1_communicationActivator : public QObject,public PluginInterface
{
    Q_OBJECT
    Q_INTERFACES(PluginInterface)
    Q_PLUGIN_METADATA(IID PluginInterface_iid)
public:
    explicit vehicle1_communicationActivator(QObject *parent = nullptr);
    void stop() override;
    void start() override;
    void init(PluginContext *CONTEXT) override;
    static void postevent(XTLevent  event)
    {
        m_CONTEXT->postevent(event);
    }
    static void registerservice(QObject* service,QString name)
    {
    m_CONTEXT->registerservice(service,name);
    };
    static void subscribevent(QString name,EventService *handle)
    {
    m_CONTEXT->subscribeslot(name,handle);
    };
    template <typename T>
    static T* getService(QString servicename)
    {

        QObject *servicehandle=m_CONTEXT->getservice(servicename);
        return dynamic_cast<T*>(servicehandle);
    }


private:
    static vehicle1_communicationActivator *m_instance;
    static PluginContext *m_CONTEXT;
    mqttpublisher *m_node;

};

#endif 
#endif
