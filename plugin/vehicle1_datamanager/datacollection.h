#ifndef DATACOLLECTION_H
#define DATACOLLECTION_H
#include <mutexobj.h>
#include <QByteArray>
#include <geometry_msgs/Twist.h>
#include <defines/Vehicle1_data.h>
#include <sensor_msgs/PointCloud.h>
class Datacollection:public mutexobj
{
public:
    Datacollection();
    void set_local_cmd(double omega, double linear_speed);
    bool setStream(V1DATA::DOWNSTREAM_INFO_ISSUED *data);
    geometry_msgs::Twist send_local_cmd();
    double local_cmd[2];
    V1DATA::USED_DATA vehicle_data;
    sensor_msgs::PointCloud m_pointcloud;
};

#endif // DATACOLLECTION_H
