#include "vehicle1_communicationActivator.h"


vehicle1_communicationActivator* vehicle1_communicationActivator::m_instance=Q_NULLPTR;
PluginContext* vehicle1_communicationActivator::m_CONTEXT=Q_NULLPTR;
vehicle1_communicationActivator::vehicle1_communicationActivator(QObject *parent) : QObject(parent),m_node(NULL)
{
    m_instance=this;
}
void vehicle1_communicationActivator::init(PluginContext *CONTEXT)
{
    m_CONTEXT=CONTEXT;
}
void vehicle1_communicationActivator::start()
{
    m_node=new mqttpublisher;

}
void vehicle1_communicationActivator::stop()
{
delete this;

}
