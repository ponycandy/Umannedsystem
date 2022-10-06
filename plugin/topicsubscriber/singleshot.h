#ifndef SINGLESHOT_H
#define SINGLESHOT_H

#include <QObject>
#include <ros/ros.h>
class Singleshot : public QObject
{
    Q_OBJECT

public:
    explicit Singleshot(QObject *parent = nullptr);
    ros::NodeHandlePtr nh_;
    ros::Publisher pub_1;
signals:

};

#endif // SINGLESHOT_H
