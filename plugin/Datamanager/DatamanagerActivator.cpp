#include "DatamanagerActivator.h"


DatamanagerActivator* DatamanagerActivator::m_instance=Q_NULLPTR;
PluginContext* DatamanagerActivator::m_CONTEXT=Q_NULLPTR;
DatamanagerActivator::DatamanagerActivator(QObject *parent) : QObject(parent),m_collector(NULL)
{
    m_instance=this;
}
void DatamanagerActivator::init(PluginContext *CONTEXT)
{
    m_CONTEXT=CONTEXT;
}
void DatamanagerActivator::start()
{
    if (m_collector==NULL)
    {
        m_collector=new messagecollector;
    }

}
void DatamanagerActivator::stop()
{
delete this;

}
