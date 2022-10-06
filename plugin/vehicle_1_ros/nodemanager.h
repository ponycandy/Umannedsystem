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
    void chatterCallback(const sensor_msgs::PointCloud data);
    void chatterCallback1(const sensor_msgs::Joy data);
    void EventTriggeres(XTLevent event) override;
    Singleshot *m_pub_once;

private:
    ros::NodeHandlePtr nh_;
    QTimer *ros_timer;
    ros::V_string v_nodes;
    QStringList m_list;
    QString state_Nokl;
signals:
    void start_node();
    void stop_node();
    void sig_setHandle(ros::NodeHandlePtr);
    void sig_setservice();
    void sig_start_pubthread();
    void sig_switch_control(XTLevent event);
    void sig_start_pubthread_remote();
    void sig_start_pubthread_local();
    void sig_stop_pubthread();


private slots:
    void spinOnce();
    void slotsig_start_pubthread_remote();
    void slotsig_start_pubthread_local();

    void slotsig_stop_pubthread();




signals:

};

#endif // NODEMANAGER_H
