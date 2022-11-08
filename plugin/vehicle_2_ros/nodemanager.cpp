#include "nodemanager.h"
#include "vehicle_2_rosActivator.h"
#include "QtDebug"
#include "defines/vehicle_2_data.h"
nodemanager::nodemanager(QObject *parent) : QObject(parent),
    nh_(NULL),  ros_timer(NULL)
{
    m_pub_once=new Singleshot;
    state_Nokl="stop";
    qRegisterMetaType<XTLevent>("XTLevent");
    qRegisterMetaType<ros::NodeHandlePtr>("ros::NodeHandlePtr");
    vehicle_2_rosActivator::registerservice(m_pub_once,"vehicle_2_rosservice");
}



void nodemanager::EventTriggeres(XTLevent event)
{

}


