#include "singleshot.h"
#include <vehicle_1_rosActivator.h>
#include <sensor_msgs/Image.h>
#include <QImage>
#include <QtDebug>
Singleshot::Singleshot(QObject *parent) : QObject(parent),nh_(nullptr)
{
        nh_.reset(new ros::NodeHandle);

        std::string v1point_cloud_data;
        nh_->param<std::string>("/v1point_cloud_data",v1point_cloud_data,"/v1point_cloud_data");
        pub_1=nh_->advertise<sensor_msgs::PointCloud>(v1point_cloud_data,1);

        std::string v1_imagedata_1;
        nh_->param<std::string>("/v1_imagedata_1",v1_imagedata_1,"/v1_imagedata_1");
        pub_2=nh_->advertise<sensor_msgs::Image>(v1_imagedata_1,1);

        std::string v1_laserscan;
        nh_->param<std::string>("/v1_laserscan",v1_laserscan,"/v1_laserscan");
        pub_1=nh_->advertise<sensor_msgs::PointCloud>(v1_laserscan,1);


}

void Singleshot::pub(V1DATA::SHARED_POINTCLOUD cloud_ptr)
{
    sensor_msgs::PointCloud m_pointcloud;


    m_pointcloud.header.seq=cloud_ptr.SH_POINTCLOUD.data()->secquense;
    m_pointcloud.header.stamp.sec=cloud_ptr.SH_POINTCLOUD.data()->time.secs;
    m_pointcloud.header.stamp.nsec=cloud_ptr.SH_POINTCLOUD.data()->time.nsecs;
    m_pointcloud.header.frame_id="laser_frame";
    m_pointcloud.channels.resize(2);
    m_pointcloud.channels[0].name="intensities";
    m_pointcloud.channels[1].name="stamps";
    for(int i=0;i<cloud_ptr.SH_POINTCLOUD.data()->pointnum;i++)
    {
        geometry_msgs::Point32 point;
        point.x =cloud_ptr.SH_POINTCLOUD.data()->point_group[i].x;
        point.y = cloud_ptr.SH_POINTCLOUD.data()->point_group[i].y;
        point.z = 0;
        m_pointcloud.points.push_back(point);
        m_pointcloud.channels[0].values.push_back(cloud_ptr.SH_POINTCLOUD.data()->point_group[i].intensity);
        m_pointcloud.channels[1].values.push_back(cloud_ptr.SH_POINTCLOUD.data()->point_group[i].timestamp);
    }
    pub_1.publish(m_pointcloud);
}

void Singleshot::pub(QSharedPointer<QImage> image_ptr)
{

    sensor_msgs::Image pub_image;
    QImage *image_data=image_ptr.data();
    pub_image.height=image_data->height();
    pub_image.width=image_data->width();
//still do not know how to assign other parts of pub_image
    //ros time will be available from fram meta data
}

void Singleshot::pub(V1DATA::LASER_SCAN cloud_ptr)
{

}
