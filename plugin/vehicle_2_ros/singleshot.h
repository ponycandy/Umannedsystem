#ifndef SINGLESHOT_H
#define SINGLESHOT_H

#include <QObject>
#include <ros/ros.h>
#include <service/vehicle_2_rosservice.h>
class Singleshot : public QObject,public vehicle_2_rosservice
{
    Q_OBJECT

public:
    explicit Singleshot(QObject *parent = nullptr);
    ros::NodeHandlePtr nh_;
    ros::Publisher pub_1;
    ros::Publisher pub_2;

signals:

};

#endif // SINGLESHOT_H
