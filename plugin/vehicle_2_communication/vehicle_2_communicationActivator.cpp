#include "vehicle_2_communicationActivator.h"


vehicle_2_communicationActivator* vehicle_2_communicationActivator::m_instance=Q_NULLPTR;
PluginContext* vehicle_2_communicationActivator::m_CONTEXT=Q_NULLPTR;
vehicle_2_communicationActivator::vehicle_2_communicationActivator(QObject *parent) : QObject(parent),m_node(NULL)
{
    m_instance=this;
}
void vehicle_2_communicationActivator::init(PluginContext *CONTEXT)
{
    m_CONTEXT=CONTEXT;
}
void vehicle_2_communicationActivator::start()
{
    m_node=new mqttpublisher;

}
void vehicle_2_communicationActivator::stop()
{
delete this;

}
