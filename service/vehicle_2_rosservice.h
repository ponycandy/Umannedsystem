
#ifndef VEHICLE_2_ROSSERVICE_H
#define VEHICLE_2_ROSSERVICE_H

#include <QObject>
class vehicle_2_rosservice
{
public:
    virtual ~vehicle_2_rosservice(){}

};
#define vehicle_2_rosservice_iid "vehicle_2_rosservice"

QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(vehicle_2_rosservice,vehicle_2_rosservice_iid  )
QT_END_NAMESPACE

#endif

