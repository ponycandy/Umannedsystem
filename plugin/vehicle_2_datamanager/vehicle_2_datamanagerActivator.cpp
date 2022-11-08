#include "vehicle_2_datamanagerActivator.h"


vehicle_2_datamanagerActivator* vehicle_2_datamanagerActivator::m_instance=Q_NULLPTR;
PluginContext* vehicle_2_datamanagerActivator::m_CONTEXT=Q_NULLPTR;
vehicle_2_datamanagerActivator::vehicle_2_datamanagerActivator(QObject *parent) : QObject(parent),m_collector(nullptr)
{
    m_instance=this;
}
void vehicle_2_datamanagerActivator::init(PluginContext *CONTEXT)
{
    m_CONTEXT=CONTEXT;
}
void vehicle_2_datamanagerActivator::start()
{
    if (m_collector==NULL)
    {
        m_collector=new messagecollector;
    }
}
void vehicle_2_datamanagerActivator::stop()
{
delete this;

}
