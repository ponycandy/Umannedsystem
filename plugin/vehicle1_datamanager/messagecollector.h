#ifndef MESSAGECOLLECTOR_H
#define MESSAGECOLLECTOR_H

#include <QObject>
#include <service/Datamanageservice.h>
#include <service/vehicle_1_1Datamanageservice.h>
#include <sensor_msgs/PointCloud.h>
#include <datacollection.h>
#include <smartptr.h>
#include <geometry_msgs/Twist.h>

#include "netparser.h"
class messagecollector : public QObject,public vehicle_1_1Datamanageservice
{
    Q_OBJECT
    Q_INTERFACES(vehicle_1_1Datamanageservice)
public:
    explicit messagecollector(QObject *parent = nullptr);
    void store(QSharedPointer<QByteArray> input) override;
    void execute(V1DATA::PLUSED_SWITCH_DATA ptopic, QByteArray &sending_data) override;
    void execute(V1DATA::MOTIONCOMMAND ptopic, QByteArray &sending_data) override;
    bool execute(const char *data, int len, V1DATA::DOWNSTREAM_INFO &ptTopic);
    bool execute(const char *data, int len, V1DATA::DOWNSTREAM_INFO_ISSUED &ptTopic);

    void parse(const char *data, V1DATA::POINTCLOUD &PTtopic) override;
    Datacollection *m_Data;
    char m_protcols_data[64];
    char m_control_cmd[64];

    SmartPtr<Datacollection> m_Data_Ptr;
signals:

};

#endif // MESSAGECOLLECTOR_H
