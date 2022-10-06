
#ifndef VEHICLE_1_1DATAMANAGESERVICE_H
#define VEHICLE_1_1DATAMANAGESERVICE_H

#include <QObject>
#include <defines/Vehicle1_data.h>
class vehicle_1_1Datamanageservice
{
public:
    virtual ~vehicle_1_1Datamanageservice(){}
    virtual void store(QSharedPointer<QByteArray> input)=0;
    virtual void execute(V1DATA::PLUSED_SWITCH_DATA ptopic,QByteArray &sending_data)=0;
    virtual void execute(V1DATA::MOTIONCOMMAND ptopic, QByteArray &sending_data)=0;

    virtual void parse(const char *data,V1DATA::POINTCLOUD &PTtopic)=0;

};
#define vehicle_1_1Datamanageservice_iid "vehicle_1_1Datamanageservice"

QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(vehicle_1_1Datamanageservice,vehicle_1_1Datamanageservice_iid  )
QT_END_NAMESPACE

#endif

