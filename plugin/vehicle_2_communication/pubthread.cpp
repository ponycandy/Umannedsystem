#include "pubthread.h"
#include "vehicle_2_communicationActivator.h"
#include "QtDebug"
#include "delay_thread_time.h"
pubthread::pubthread(QObject *parent)
{
    client=new QMQTT::Client;
    vehicle_2_communicationActivator::registerservice(this,"vehicle_2_communicationservice");
}

void pubthread::send(QByteArray data)
{
    QMQTT::Message message;
    message.setId(0);
    message.setQos(0);
    message.setTopic(topicname);
    message.setPayload(data);
    client->publish(message);

}
void pubthread::slot_start_node()
{
    client->connectToHost();
}

void pubthread::slot_stop_node()
{
    client->disconnectFromHost();
}

void pubthread::slot_setNet(XTLevent event)
{
    QString plos_sk=event.m_dict.value("cilentID(S)").toString();
    char* plos=plos_sk.toLatin1().data();
    char *plo=new char[64];
    memset(plo,0x00,64);
    memcpy(plo,plos,plos_sk.length());

    QString plos_sk1=event.m_dict.value("port(S)").toString();
    char* plos1=plos_sk1.toLatin1().data();
    char *plo1=new char[64];
    memset(plo1,0x00,64);
    memcpy(plo1,plos1, plos_sk1.length());

    QString plos_sk2=event.m_dict.value("host(S)").toString();
    char* plos2=plos_sk2.toLatin1().data();
    char *plo2=new char[64];
    memset(plo2,0x00,64);
    memcpy(plo2,plos2,plos_sk2.length());

    QString plos_sk3=event.m_dict.value("username(S)").toString();
    char* plos3=plos_sk3.toLatin1().data();
    char *plo3=new char[64];
    memset(plo3,0x00,64);
    memcpy(plo3,plos3,plos_sk3.length());

    QString plos_sk4=event.m_dict.value("password(S)").toString();
    char* plos4=plos_sk4.toLatin1().data();
    char *plo4=new char[64];
    memset(plo4,0x00,64);
    memcpy(plo4,plos4,plos_sk4.length());

    QString plos_sk5=event.m_dict.value("topicname(S)").toString();
    char* plos5=plos_sk5.toLatin1().data();
    char *plo5=new char[64];
    memset(plo5,0x00,64);
    memcpy(plo5,plos5,plos_sk5.length());

    client->setHost(QHostAddress(plo2));
    client->setClientId(plos_sk);
    client->setUsername(plos_sk3);
    client->setPassword(plo4);

//    client->setHost(QHostAddress("101.43.33.201"));
//    client->setClientId("UCS_to_vehicle1_send");
//    client->setUsername("UCS_to_vehicle1_send");
//    client->setPassword("public");
    topicname=plo5;
    //    mqtt_set_clean_session(m_client, 1);
    //    mqtt_set_version(m_client, 3);
}

