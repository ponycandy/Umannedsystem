#include "vehicle_1_rosActivator.h"


vehicle_1_rosActivator* vehicle_1_rosActivator::m_instance=Q_NULLPTR;
PluginContext* vehicle_1_rosActivator::m_CONTEXT=Q_NULLPTR;
vehicle_1_rosActivator::vehicle_1_rosActivator(QObject *parent) : QObject(parent)
{
    m_instance=this;
}
void vehicle_1_rosActivator::init(PluginContext *CONTEXT)
{
    m_CONTEXT=CONTEXT;
}
void vehicle_1_rosActivator::start()
{
    m_manager=new nodemanager;
}
void vehicle_1_rosActivator::stop()
{
delete this;

}
