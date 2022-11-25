#ifndef SINGLESHOT_H
#define SINGLESHOT_H

#include <QObject>
#include <ros/ros.h>
#include <service/vehicle_1_rosservice.h>
class Singleshot : public QObject,public vehicle_1_rosservice
{
    Q_OBJECT

public:
    explicit Singleshot(QObject *parent = nullptr);
    void pub(V1DATA::SHARED_POINTCLOUD cloud_ptr) override;
    void pub(QSharedPointer<QImage> image_ptr) override;
    void pub(V1DATA::LASER_SCAN cloud_ptr) override;
    ros::NodeHandlePtr nh_;
    ros::Publisher pub_1;
    ros::Publisher pub_2;

signals:

};

#endif // SINGLESHOT_H
