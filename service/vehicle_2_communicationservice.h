
#ifndef VEHICLE_2_COMMUNICATIONSERVICE_H
#define VEHICLE_2_COMMUNICATIONSERVICE_H

#include <QObject>
class vehicle_2_communicationservice
{
public:
    virtual ~vehicle_2_communicationservice(){}
    virtual void send(QByteArray data)=0;

};
#define vehicle_2_communicationservice_iid "vehicle_2_communicationservice"

QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(vehicle_2_communicationservice,vehicle_2_communicationservice_iid  )
QT_END_NAMESPACE

#endif

