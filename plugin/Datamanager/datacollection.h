#ifndef DATACOLLECTION_H
#define DATACOLLECTION_H
#include <mutexobj.h>
#include <QByteArray>
#include <geometry_msgs/Twist.h>

class Datacollection:public mutexobj
{
public:
    Datacollection();
    void set_local_cmd(double omega, double linear_speed);
    geometry_msgs::Twist send_local_cmd();
    double local_cmd[2];
};

#endif // DATACOLLECTION_H
