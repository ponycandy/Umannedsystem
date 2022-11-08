#ifndef SUBTHREAD_H
#define SUBTHREAD_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <sstream>
#include <qmetatype.h>
#include <QObject>
#include <qmqtt.h>
#include <xtlevent.h>
#include <service/vehicle_2_Datamanageservice.h>
#include <QSharedPointer>
#include <service/vehicle_2_rosservice.h>
class subthread : public QObject
{
    Q_OBJECT
public:
    explicit subthread(QObject *parent = nullptr);
    int on_sub=0;
    QString topicname;
    vehicle_2_Datamanageservice *m_service;
    int flag;
    QMQTT::Client *client;
    vehicle_2_rosservice *m_service_ros;

private slots:
    void slot_start_node();
    void slot_stop_node();
    void slot_setNet(XTLevent event);
    void onConnected();
    void onReceived(const QMQTT::Message& message);
//    void parse(const char* data,V1DATA::POINTCLOUD &PTtopic);

};

#endif // SUBTHREAD_H
