
#ifndef VEHICLE_1_ROSSERVICE_H
#define VEHICLE_1_ROSSERVICE_H

#include <QObject>
#include <defines/Vehicle1_data.h>
#include <QSharedPointer>
class vehicle_1_rosservice
{
public:
    virtual ~vehicle_1_rosservice(){}
    virtual void pub(V1DATA::SHARED_POINTCLOUD cloud_ptr)=0;
    virtual void pub(V1DATA::LASER_SCAN cloud_ptr)=0;

    virtual void pub(QSharedPointer<QImage> image_ptr)=0;

};
#define vehicle_1_rosservice_iid "vehicle_1_rosservice"

QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(vehicle_1_rosservice,vehicle_1_rosservice_iid  )
QT_END_NAMESPACE

#endif

