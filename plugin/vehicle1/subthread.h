#ifndef SUBTHREAD_H
#define SUBTHREAD_H

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

class subthread : public QObject
{
    Q_OBJECT
public:
    explicit subthread(QObject *parent = nullptr);
    mqtt_client_t *m_client;
    int on_sub=0;
    char* topicname;
    static void topic_handler(void* client, message_data_t* msg);
    static Datamanageservice *m_service;
private slots:
    void slot_start_node();
    void slot_stop_node();
    void slot_setNet(XTLevent event);

};

#endif // SUBTHREAD_H
