#include "datacollection.h"

Datacollection::Datacollection()
{
    m_pointcloud.header.frame_id="lidar_scan";
    m_pointcloud.channels.resize(2);
    m_pointcloud.channels[0].name="intensities";
    m_pointcloud.channels[1].name="stamps";

}

void Datacollection::set_local_cmd(double omega, double linear_speed)
{
    local_cmd[0]=linear_speed;
    local_cmd[1]=omega;

}

bool Datacollection::setStream(V1DATA::DOWNSTREAM_INFO_ISSUED *data)
{
    m_pointcloud.header.seq=data->m_cloud.secquense;
    m_pointcloud.header.stamp.sec=data->m_cloud.time.secs;
    m_pointcloud.header.stamp.nsec=data->m_cloud.time.nsecs;
    int areanum=data->m_cloud.pointnum;
    m_pointcloud.points.resize(areanum);
    for(int i = 0;i < areanum;i++)
    {
        m_pointcloud.points[i].x=data->m_cloud.point_group[i].x;
        m_pointcloud.points[i].y=data->m_cloud.point_group[i].y;
        m_pointcloud.points[i].z=0;
        m_pointcloud.channels[0].values.push_back(data->m_cloud.point_group[areanum-1-i].intensity);
        m_pointcloud.channels[1].values.push_back(data->m_cloud.point_group[areanum-1-i].timestamp);

    }

}

geometry_msgs::Twist Datacollection::send_local_cmd()
{
    geometry_msgs::Twist cmd;
    cmd.linear.x=local_cmd[0];
    cmd.angular.z=local_cmd[1];
    return  cmd;
}
