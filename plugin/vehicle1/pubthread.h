#ifndef PUBTHREAD_H
#define PUBTHREAD_H
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <sstream>
#include <qmetatype.h>
extern "C"
{
#include "libmqttclient/include/mqttclient.h"
}
#include <QObject>
#include <xtlevent.h>
#include <service/Datamanageservice.h>
class pubthread : public QObject
{
    Q_OBJECT
public:
    explicit pubthread(QObject *parent = nullptr);
    int mqtt_publish_handle(mqtt_client_t *client);
    int on_pub=0;//make sure this type is atomic on your system
    mqtt_client_t *m_client;
    char* topicname;
    Datamanageservice *servicehandle;

private slots:
    void slot_start_node();
    void slot_stop_node();
    void slot_setNet(XTLevent event);
signals:

};

#endif // PUBTHREAD_H
