#include "vehicle1_datamanagerActivator.h"


vehicle1_datamanagerActivator* vehicle1_datamanagerActivator::m_instance=Q_NULLPTR;
PluginContext* vehicle1_datamanagerActivator::m_CONTEXT=Q_NULLPTR;
vehicle1_datamanagerActivator::vehicle1_datamanagerActivator(QObject *parent) : QObject(parent),m_collector(NULL)
{
    m_instance=this;
}
void vehicle1_datamanagerActivator::init(PluginContext *CONTEXT)
{
    m_CONTEXT=CONTEXT;
}
void vehicle1_datamanagerActivator::start()
{
    if (m_collector==NULL)
    {
        m_collector=new messagecollector;
    }

}
void vehicle1_datamanagerActivator::stop()
{
delete this;

}
