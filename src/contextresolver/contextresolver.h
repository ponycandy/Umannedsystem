#ifndef QTPLUGIN_H
#define QTPLUGIN_H

#include <QObject>
#include <QtPlugin>
#include "plugincontext.h"
#include <QMap>
#include <service/eventservice.h>
#include "slotpointer.h"
#include "funcdummy.h"
class ContextResolver : public QObject,public PluginContext
{
    Q_OBJECT
    Q_INTERFACES(PluginContext)
    Q_PLUGIN_METADATA(IID PluginContext_iid)//file json is not needed
public:
    explicit ContextResolver(QObject *parent = nullptr);
    QObject* getservice(QString name) override;
    void setupevent() override;
    void publishsignal(QObject *sender, const char *signal, QString eventname,Qt::ConnectionType type) override;
    void postevent(XTLevent event) override;
    void subscribeslot(QObject *reciever, const char *method, QString eventname,Qt::ConnectionType type) override;
    void registerservice(QObject *service,QString name) override;
    void subscribeslot(QString name,EventService *handle) override;
    void tryconnection_slot(QString eventname,QObject *sender,const char *signal);
    void tryconnection_sig(QString eventname,QObject *reciever,const char *slot);

    QMap<QString ,FuncDummy*> reciever_map;
    QMap<QString ,FuncDummy*> sender_map;

signals:

private:
    int receiver_map_count=0;
    int sender_map_count=0;
    QMap<QString ,QObject*> service_map;
    QMap<QString ,SlotPointer*> event_map;




};

#endif // QTPLUGIN_H

