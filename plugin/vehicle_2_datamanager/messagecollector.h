#ifndef MESSAGECOLLECTOR_H
#define MESSAGECOLLECTOR_H

#include <QObject>
#include <service/Datamanageservice.h>
#include <service/vehicle_2_Datamanageservice.h>
#include <sensor_msgs/PointCloud.h>
#include <datacollection.h>
#include <smartptr.h>
#include <geometry_msgs/Twist.h>

#include "netparser.h"
class messagecollector : public QObject,public vehicle_2_Datamanageservice
{
    Q_OBJECT
    Q_INTERFACES(vehicle_2_Datamanageservice)
public:
    explicit messagecollector(QObject *parent = nullptr);
    void store(QSharedPointer<QByteArray> input) override;
    void execute(VEHICLE_2_DATA::MOTIONCOMMAND ptopic, QByteArray &sending_data) override;
    void execute(VEHICLE_2_DATA::PLUSED_SWITCH_DATA ptopic, QByteArray &sending_data) override;
    Datacollection *m_Data;
    char m_protcols_data[64];
    char m_control_cmd[64];

    SmartPtr<Datacollection> m_Data_Ptr;
signals:

};

#endif // MESSAGECOLLECTOR_H
