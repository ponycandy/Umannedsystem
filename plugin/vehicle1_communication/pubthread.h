#ifndef PUBTHREAD_H
#define PUBTHREAD_H
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <sstream>
#include <qmetatype.h>
#include <QObject>
#include <qmqtt.h>
#include <xtlevent.h>
#include <service/vehicle1_communicationservice.h>
class pubthread : public QObject,public vehicle1_communicationservice
{
    Q_OBJECT
public:
    explicit pubthread(QObject *parent = nullptr);
    int on_pub=0;//make sure this type is atomic on your system
    QString topicname;
    QMQTT::Client *client;

    void send(QByteArray data) override;


private slots:
    void slot_start_node();
    void slot_stop_node();
    void slot_setNet(XTLevent event);
signals:

};

#endif // PUBTHREAD_H
