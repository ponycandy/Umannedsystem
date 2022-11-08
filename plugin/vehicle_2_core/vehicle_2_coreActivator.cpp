#include "vehicle_2_coreActivator.h"


vehicle_2_coreActivator* vehicle_2_coreActivator::m_instance=Q_NULLPTR;
PluginContext* vehicle_2_coreActivator::m_CONTEXT=Q_NULLPTR;
vehicle_2_coreActivator::vehicle_2_coreActivator(QObject *parent) : QObject(parent),m_startwindow(NULL)
{
    m_instance=this;
}
void vehicle_2_coreActivator::init(PluginContext *CONTEXT)
{
    m_CONTEXT=CONTEXT;
}
void vehicle_2_coreActivator::start()
{
    m_startwindow=new startwindow;

}
void vehicle_2_coreActivator::stop()
{
delete this;

}
