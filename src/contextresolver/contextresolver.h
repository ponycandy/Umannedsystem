#ifndef QTPLUGIN_H
#define QTPLUGIN_H

#include <QObject>
#include <QtPlugin>
#include "plugincontext.h"
#include <QMap>
#include <service/eventservice.h>
#include "slotpointer.h"
class ContextResolver : public QObject,public PluginContext
{
    Q_OBJECT
    Q_INTERFACES(PluginContext)
    Q_PLUGIN_METADATA(IID PluginContext_iid)//file json is not needed
public:
    explicit ContextResolver(QObject *parent = nullptr);
    QObject* getservice(QString name) override;
    void setupevent() override;
    void publishsignal() override;
    void postevent(XTLevent event) override;
    void subscribeslot(QString name,EventService *handle) override;
    void registerservice(QObject *service,QString name) override;
signals:

private:
    QMap<QString ,QObject*> service_map;
    QMap<QString ,SlotPointer*> event_map;


};

#endif // QTPLUGIN_H

