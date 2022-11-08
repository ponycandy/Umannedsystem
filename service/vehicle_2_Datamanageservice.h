
#ifndef VEHICLE_2_DATAMANAGESERVICE_H
#define VEHICLE_2_DATAMANAGESERVICE_H

#include <QObject>
#include <defines/vehicle_2_data.h>
class vehicle_2_Datamanageservice
{
public:
    virtual ~vehicle_2_Datamanageservice(){}
    virtual void store(QSharedPointer<QByteArray> input)=0;

    virtual void execute(VEHICLE_2_DATA::PLUSED_SWITCH_DATA ptopic,QByteArray &sending_data)=0;
    virtual void execute(VEHICLE_2_DATA::MOTIONCOMMAND ptopic, QByteArray &sending_data)=0;

   // virtual void parse(const char *data,V1DATA::POINTCLOUD &PTtopic)=0;

};
#define vehicle_2_Datamanageservice_iid "vehicle_2_Datamanageservice"

QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(vehicle_2_Datamanageservice,vehicle_2_Datamanageservice_iid  )
QT_END_NAMESPACE

#endif

