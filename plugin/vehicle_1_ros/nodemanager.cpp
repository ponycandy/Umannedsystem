#include "nodemanager.h"
#include "vehicle_1_rosActivator.h"
#include "QtDebug"
#include "defines/Vehicle1_data.h"
nodemanager::nodemanager(QObject *parent) : QObject(parent),
    nh_(NULL),  ros_timer(NULL),m_pub_once(NULL)
{
    m_pub_once=new Singleshot;
    state_Nokl="stop";
    qRegisterMetaType<XTLevent>("XTLevent");
    qRegisterMetaType<ros::NodeHandlePtr>("ros::NodeHandlePtr");
    vehicle_1_rosActivator::registerservice(m_pub_once,"vehicle_1_rosservice");
}

void nodemanager::spinOnce()
{
    if(ros::ok()){
        ros::spinOnce();
    }

}

void nodemanager::slotsig_start_pubthread_remote()
{
    emit sig_start_pubthread_remote();

}

void nodemanager::slotsig_start_pubthread_local()
{
    emit sig_start_pubthread_local();

}
void nodemanager::chatterCallback(const sensor_msgs::PointCloud data)
{
//    V1DATA::POINTCLOUD pointcloud_data;
//    pointcloud_data.header=0xaacc;
//    pointcloud_data.secquense=data.header.seq;

//    pointcloud_data.time.secs=data.header.stamp.sec;

//    pointcloud_data.time.nsecs=data.header.stamp.nsec;
//    pointcloud_data.pointnum=data.points.size();
//    for(int i=0;i<pointcloud_data.pointnum;i++)
//    {
//        V1DATA::SINGEPOINTDATA new_point;
//        new_point.x=data.points[i].x;
//        new_point.y=data.points[i].y;
//        new_point.intensity=data.channels[0].values[i];
//        new_point.timestamp=data.channels[1].values[i];
//        pointcloud_data.point_group.append(new_point);
//    }

//    //protocol layer done
//    QByteArray sendingdata;

//     //   qDebug()<<"sizeof pointcloud data and  pointnum"<<sizeof (pointcloud_data)<<" "<< pointcloud_data.pointnum;
//    m_datamanager->execute(pointcloud_data,sendingdata);
//    m_communication->send(sendingdata);

}
void nodemanager::chatterCallback1(const sensor_msgs::Joy data)
{
}

void nodemanager::EventTriggeres(XTLevent event)
{
    if(event.eventname==UCSEVENT::STARTROSLOOP)
    {
        QVariant signals_s=event.m_dict.value("property");
        if(signals_s.toBool()==true)
        {
            emit start_node();
            ros_timer->start(100);
        }
        else
        {
            emit stop_node();
            ros_timer->stop();

        }
        return;
    }
    if(event.eventname==UCSEVENT::ROSPUBCONTROLSIG)
    {
        emit sig_switch_control(event);
    }

}


