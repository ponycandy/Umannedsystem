
#ifndef VEHICLE1_COMMUNICATIONSERVICE_H
#define VEHICLE1_COMMUNICATIONSERVICE_H

#include <QObject>
class vehicle1_communicationservice
{
public:
    virtual ~vehicle1_communicationservice(){}
    virtual void send(QByteArray data)=0;


};
#define vehicle1_communicationservice_iid "vehicle1_communicationservice"

QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(vehicle1_communicationservice,vehicle1_communicationservice_iid  )
QT_END_NAMESPACE

#endif

