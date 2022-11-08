#ifndef VEHICLE_2_CORE_H
#define VEHICLE_2_CORE_H
#ifndef QTPLUGIN_H
#define QTPLUGIN_H

#include <QObject>
#include <QtPlugin>
#include "plugininterface.h"
#include "service/eventservice.h"
#include "startwindow.h"



class vehicle_2_coreActivator : public QObject,public PluginInterface
{
    Q_OBJECT
    Q_INTERFACES(PluginInterface)
    Q_PLUGIN_METADATA(IID PluginInterface_iid)
public:
    explicit vehicle_2_coreActivator(QObject *parent = nullptr);
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
    static vehicle_2_coreActivator *m_instance;
    static PluginContext *m_CONTEXT;
    startwindow *m_startwindow;

};

#endif 
#endif
