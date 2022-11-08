#include "singleshot.h"
#include <vehicle_2_rosActivator.h>
#include <sensor_msgs/Image.h>
#include <QImage>
Singleshot::Singleshot(QObject *parent) : QObject(parent)
{
        nh_.reset(new ros::NodeHandle);

//        std::string v1point_cloud_data;
//        nh_->param<std::string>("/v1point_cloud_data",v1point_cloud_data,"/v1point_cloud_data");
//        pub_1=nh_->advertise<sensor_msgs::PointCloud>(v1point_cloud_data,1);

//        std::string v1_imagedata_1;
//        nh_->param<std::string>("/v1_imagedata_1",v1_imagedata_1,"/v1_imagedata_1");
//        pub_2=nh_->advertise<sensor_msgs::Image>(v1_imagedata_1,1);

}
