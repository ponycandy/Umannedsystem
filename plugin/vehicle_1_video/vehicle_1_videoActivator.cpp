#include "vehicle_1_videoActivator.h"


vehicle_1_videoActivator* vehicle_1_videoActivator::m_instance=Q_NULLPTR;
PluginContext* vehicle_1_videoActivator::m_CONTEXT=Q_NULLPTR;
vehicle_1_videoActivator::vehicle_1_videoActivator(QObject *parent) : QObject(parent)
{
    m_instance=this;
}
void vehicle_1_videoActivator::init(PluginContext *CONTEXT)
{
    m_CONTEXT=CONTEXT;
}
void vehicle_1_videoActivator::start()
{
    m_video=new video_manager;

}
void vehicle_1_videoActivator::stop()
{
delete this;

}
