
#ifndef DATAMANAGESERVICE_H
#define DATAMANAGESERVICE_H

#include <QObject>

#if defined (Q_OS_WIN32)
class Datamanageservice
{
public:
    virtual ~Datamanageservice(){}

};
#else
#include <sensor_msgs/PointCloud.h>
#include <sensor_msgs/Joy.h>
#include <geometry_msgs/Twist.h>
class Datamanageservice
{
public:
    virtual ~Datamanageservice(){}
    virtual void store(const sensor_msgs::PointCloud data)=0;
    virtual void store(const sensor_msgs::Joy data)=0;
    virtual geometry_msgs::Twist send()=0;
    virtual void publishtocloud()=0;
    virtual char* copy_buffer(QByteArray data)=0;
    virtual void Demux(char* input)=0;

};
#define Datamanageservice_iid "Datamanageservice"

QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(Datamanageservice,Datamanageservice_iid  )
QT_END_NAMESPACE
#endif
#endif

