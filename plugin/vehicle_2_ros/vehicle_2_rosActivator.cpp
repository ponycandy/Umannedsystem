#include "vehicle_2_rosActivator.h"


vehicle_2_rosActivator* vehicle_2_rosActivator::m_instance=Q_NULLPTR;
PluginContext* vehicle_2_rosActivator::m_CONTEXT=Q_NULLPTR;
vehicle_2_rosActivator::vehicle_2_rosActivator(QObject *parent) : QObject(parent),m_manager(nullptr)
{
    m_instance=this;
}
void vehicle_2_rosActivator::init(PluginContext *CONTEXT)
{
    m_CONTEXT=CONTEXT;
}
void vehicle_2_rosActivator::start()
{
    m_manager=new nodemanager;

}
void vehicle_2_rosActivator::stop()
{
delete this;

}
