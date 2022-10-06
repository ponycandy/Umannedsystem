#include "vehicle1Activator.h"


vehicle1Activator* vehicle1Activator::m_instance=Q_NULLPTR;
PluginContext* vehicle1Activator::m_CONTEXT=Q_NULLPTR;
vehicle1Activator::vehicle1Activator(QObject *parent) : QObject(parent),m_car(NULL)
{
    m_instance=this;
}
void vehicle1Activator::init(PluginContext *CONTEXT)
{
    m_CONTEXT=CONTEXT;
}
void vehicle1Activator::start()
{
    m_car=new mqttmanager;
}
void vehicle1Activator::stop()
{
delete this;

}
