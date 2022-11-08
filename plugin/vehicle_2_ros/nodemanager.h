#ifndef NODEMANAGER_H
#define NODEMANAGER_H

#include <QObject>
#include <ros/ros.h>
#include <QTimer>
#include <sensor_msgs/PointCloud.h>
#include <sensor_msgs/Joy.h>
#include <service/Datamanageservice.h>
#include <QThread>
#include <service/eventservice.h>
#include <event/eventype.h>

#include "singleshot.h"
class nodemanager : public QObject,public EventService
{
    Q_OBJECT

public:
    explicit nodemanager(QObject *parent = nullptr);
    void EventTriggeres(XTLevent event) override;
    Singleshot *m_pub_once;

private:
    ros::NodeHandlePtr nh_;
    QTimer *ros_timer;
    ros::V_string v_nodes;
    QStringList m_list;
    QString state_Nokl;





signals:

};

#endif // NODEMANAGER_H
