#include "pub_thread.h"
#include "topicsubscriberActivator.h"
#include <QElapsedTimer>
#include <QCoreApplication>
#include <geometry_msgs/Twist.h>
#include "QtDebug"
#include <defines/Vehicle1_data.h>
pub_thread::pub_thread(QObject *parent) : QObject(parent)
{
    topicsubscriberActivator::subscribevent(UCSEVENT::ROSPOINTCLOUDRECIEVED,this);
    nh_.reset(new ros::NodeHandle);
    std::string pointcloud;
    nh_->param<std::string>("/point_cloud",pointcloud,"/point_cloud");
    pub_1=nh_->advertise<sensor_msgs::PointCloud>(pointcloud,1);

}

void pub_thread::EventTriggeres(XTLevent event)
{
    if(event.eventname==UCSEVENT::ROSPOINTCLOUDRECIEVED)
    {
        sensor_msgs::PointCloud m_pointcloud;
        QVariant data=   event.m_dict.value("property");
        if(data.canConvert<V1DATA::POINTCLOUD>())
        {
            V1DATA::POINTCLOUD recieved_cloud = data.value<V1DATA::POINTCLOUD>();
            m_pointcloud.header.seq=recieved_cloud.secquense;
            m_pointcloud.header.stamp.sec=recieved_cloud.time.secs;
            m_pointcloud.header.stamp.nsec=recieved_cloud.time.nsecs;
            m_pointcloud.header.frame_id="laser_frame";
            m_pointcloud.channels.resize(2);
            m_pointcloud.channels[0].name="intensities";
            m_pointcloud.channels[1].name="stamps";
            for(int i=0;i<recieved_cloud.pointnum;i++)
            {
                geometry_msgs::Point32 point;
                point.x =recieved_cloud.point_group[i].x;
                point.y = recieved_cloud.point_group[i].y;
                point.z = 0;
                m_pointcloud.points.push_back(point);
                m_pointcloud.channels[0].values.push_back(recieved_cloud.point_group[i].intensity);
                m_pointcloud.channels[1].values.push_back(recieved_cloud.point_group[i].timestamp);
            }
            pub_1.publish(m_pointcloud);

        }
    }


}

void pub_thread::setservice()
{
    servicehandle=topicsubscriberActivator::getService<Datamanageservice>("Datamanageservice");
}

void pub_thread::setHandle(ros::NodeHandlePtr nh)
{


}

void pub_thread::switch_control(XTLevent event)
{
    QVariant signals_s=event.m_dict.value("property");
    if(signals_s.toString()=="remote")
    {
        on_remote=1;on_local=0;
        return;
    }
    if(signals_s.toString()=="local")
    {
        on_remote=0;on_local=1;
        return;
    }
    if(signals_s.toString()=="stop")
    {
        on_remote=0;on_local=0;
        return;
    }
    return;

}

void pub_thread::startpub()
{


}

void pub_thread::stoppub()
{
    on_pub=0;

}

